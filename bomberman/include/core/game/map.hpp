#ifndef CORE_MAP_H_
#define CORE_MAP_H_

#include "utils/encodable.hpp"
#include "utils/geom/vec.hpp"

class Map: public Encodable
{
public:
    /**
     * ex: Map::Tile::EMPTY, Map::Tile::IWALL
     */
    enum class Tile
    {
        EMPTY = 0,
        IWALL = 1,
        DWALL = 2,

        LIFE = 10,
        BOMB = 11,
        RANGE = 12,
    };

public:
    enum class Type
    {
        MARIO = 0,
        FOREST = 1,
        SNOW = 2,
        SAND = 3,
        URBAN = 4,
    };

public:
    Map(unsigned int width, unsigned int height, Tile *tiles = nullptr, bool owned = false);
    Map(unsigned int width, unsigned int height, Tile tile);
    ~Map();

public:
    /**
     * Get a modifiable tile from map.
     *
     * ~~~
     * Map::Tile tile = map.at(0, 0);
     * map.at(1, 2) = tile;
     * ~~~
     *
     * @param int x
     * @param int y
     * @return   The tile. :)
     */
    Tile &at(unsigned int x, unsigned int y);
    Tile &at(const Vec2u &pos);

    /**
     * Get a constant tile from map.
     *
     * ~~~
     * Map::Tile tile = map.at(0, 0);
     * ~~~
     *
     * @param int x
     * @param int y
     * @return   The tile. :)
     */
    const Tile &at(unsigned int x, unsigned int y) const;
    const Tile &at(const Vec2u &pos) const;

public:
    bool check(const Vec2u &pos, bool checkCollide = true) const;
    bool check(unsigned int x, unsigned int y, bool checkCollide = true) const;

public:
    const Vec2u &getSize() const;

    Vec2u randPos();

public:
    virtual void encode(cpacker_buf_t *buf) const;
    static Map *decode(cpacker_buf_t *buf);

    static Map *decodeStream(std::istream &in);

private:
    Tile empty;
    Tile *tiles;
    bool owned;
    Vec2u size;

public:
    Type type;

public:
    static Map *load_str(unsigned int width, unsigned int height, const char *data);
};

#endif /* CORE_MAP_H_ */
