#ifndef UTILS_GEOM_RECT_H_
#define UTILS_GEOM_RECT_H_

#include "utils/geom/vec.hpp"
#include "core/debug.hpp"

template<typename Type>
class Rect
{
public:
    inline Rect(Vec2<Type> pos, Vec2<Type> size)
        : pos(pos)
        , size(size)
    {}

    inline Rect(Type x, Type y, Type width, Type height)
        : pos(x, y)
        , size(width, height)
    {
    }

public:
    inline bool contains(Vec2<Type> &point)
    {
        Vec2<Type> offset = point - this->pos;
        return (offset.x() >= 0 && offset.x() < this->size.x()
             && offset.y() >= 0 && offset.y() < this->size.y());
    }

    inline bool contains(Type x, Type y)
    {
        Vec2<Type> pos(x, y);
        return contains(pos);
    }

public:
    Vec2<Type> pos;
    Vec2<Type> size;
};

#endif /* UTILS_GEOM_RECT_H_ */
