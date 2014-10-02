#include <stdlib.h>
#include "core/game/map.hpp"

Map::Map(unsigned int width, unsigned int height, Map::Tile *tiles, bool owned)
    : tiles(tiles)
    , size(width, height)
    , empty(Map::Tile::IWALL)
    , owned(owned)
    , type(Type::MARIO)
{
}

Map::Map(unsigned int width, unsigned int height, Map::Tile tile)
    : Map(width, height, new Map::Tile[width * height], true)
{
    for (unsigned int i = 0; i < width * height; ++i)
    {
        this->tiles[i] = tile;
    }
}

Map::~Map()
{
    if (owned)
    {
        delete this->tiles;
    }
}

Map::Tile &Map::at(unsigned int x, unsigned int y)
{
    if (!this->check(x, y, false))
    {
        return this->empty;
    }

    unsigned int index = y * this->size.x() + x;
    return this->tiles[index];
}

Map::Tile &Map::at(const Vec2u &pos)
{
    return this->at(pos.x(), pos.y());
}

const Map::Tile &Map::at(unsigned int x, unsigned int y) const
{
    if (x < 0 || x >= this->size.x()
        || y < 0 || y >= this->size.y())
        return this->empty;

    unsigned int index = y * this->size.x() + x;
    return this->tiles[index];
}

const Map::Tile &Map::at(const Vec2u &pos) const
{
    return this->at(pos.x(), pos.y());
}

bool Map::check(const Vec2u &pos, bool checkCollide) const
{
    if (pos.x() < 0 || pos.x() >= this->size.x()
        || pos.y() < 0 || pos.y() >= this->size.y())
        return false;

    Map::Tile tile = this->at(pos);
    if (checkCollide && (tile == Tile::IWALL || tile == Tile::DWALL))
        return false;

    return true;
}

bool Map::check(unsigned int x, unsigned int y, bool checkCollide) const
{
    Vec2u pos(x, y);
    return this->check(pos, checkCollide);
}

const Vec2u &Map::getSize() const
{
    return this->size;
}

Vec2u Map::randPos()
{
    Vec2u pos(rand() % this->size.x(), rand() % this->size.y());

    Tile &tile = at(pos);
    tile = Tile::EMPTY;

    return pos;
}

Map *Map::load_str(unsigned int width, unsigned int height, const char *data)
{
    Map::Tile *tiles = new Map::Tile[width * height];
    for (unsigned int y = 0; y < height; ++y)
    {
        for (unsigned int x = 0; x < width; ++x)
        {
            unsigned int index = y * width + x;
            Map::Tile *tile = &(tiles[index]);

            switch (data[index])
            {
                case 'x':
                    *tile = Map::Tile::IWALL;
                    break;

                case 'o':
                    *tile = Map::Tile::DWALL;
                    break;

                case ' ':
                default:
                    *tile = Map::Tile::EMPTY;
                    break;
            }
        }
    }
    return new Map(width, height, tiles);
}

void Map::encode(cpacker_buf_t *buf) const
{
    cpacker_buf_put_uint8(buf, (uint8_t)this->type);
    cpacker_buf_put_size(buf, this->size.x());
    cpacker_buf_put_size(buf, this->size.y());

    unsigned int size = this->size.x() * this->size.y();
    for (unsigned int i = 0; i < size; ++i)
    {
        Map::Tile tile = this->tiles[i];
        cpacker_buf_put_uint8(buf, (uint8_t)tile);
    }
}

Map *Map::decode(cpacker_buf_t *buf)
{
    Map::Type type = (Map::Type)cpacker_buf_read_uint8(buf);
    unsigned int width = cpacker_buf_read_size(buf);
    unsigned int height = cpacker_buf_read_size(buf);
    Map::Tile *tiles = new Map::Tile[width * height];

    for (unsigned int i = 0; i < width * height; ++i)
    {
        tiles[i] = (Map::Tile)cpacker_buf_read_uint8(buf);
    }

    Map *map = new Map(width, height, tiles, true);
    map->type = type;

    return map;
}

Map *Map::decodeStream(std::istream &in)
{
    cpacker_buf_t buf;

    cpacker_buf_init(&buf);

    in.seekg(0, in.end);
    unsigned int length = in.tellg();
    in.seekg(0, in.beg);

    cpacker_buf_ensure_size(&buf, length);
    in.read(cpacker_buf_data(&buf), length);

    Map *map = Map::decode(&buf);

    cpacker_buf_destroy(&buf);

    return map;
}
