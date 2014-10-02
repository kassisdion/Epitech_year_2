#ifndef VEC_H_
#define VEC_H_

#include <stdexcept>
#include <array>

template<typename Type, unsigned int Size>
class Vec: public std::array<Type, Size>
{
public:
    inline Vec()
        : std::array<Type, Size>()
    {}

    inline Vec(const std::array<Type, Size> &arr)
        : std::array<Type, Size>(arr)
    {}

    inline Vec(const Vec<Type, Size> &other)
        : std::array<Type, Size>(other)
    {}

public:
    inline Vec<Type, Size> operator+(Vec<Type, Size> &other)
    {
        Vec<Type, Size> result;
        for (unsigned int i = 0; i < Size; i++)
        {
            result[i] = (*this)[i] + other[i];
        }
        return result;
    }

    inline Vec<Type, Size> operator-(Vec<Type, Size> &other)
    {
        Vec<Type, Size> result;
        for (unsigned int i = 0; i < Size; i++)
        {
            result[i] = (*this)[i] - other[i];
        }
        return result;
    }
};

template<typename Type>
class Vec2: public Vec<Type, 2>
{
public:
    inline Vec2()
        : Vec<Type, 2>()
    {}

    inline Vec2(Type x, Type y)
        : Vec<Type, 2>({x, y})
    {}

    inline Vec2(const Vec2<Type> &other)
        : Vec<Type, 2>(other)
    {}

    inline Vec2(const Vec<Type, 2> &other)
        : Vec<Type, 2>(other)
    {}

public:
    inline const Type &x() const
    {
        return (*this)[0];
    }
    inline Type &x()
    {
        return (*this)[0];
    }
    inline Vec2<Type> &x(Type x)
    {
        this->x() = x;
        return *this;
    }

    inline const Type &y() const
    {
        return (*this)[1];
    }
    inline Type &y()
    {
        return (*this)[1];
    }
    inline Vec2<Type> &y(Type y)
    {
        this->y() = y;
        return *this;
    }
};

template<typename Type>
class Vec3: public Vec<Type, 3>
{
public:
    inline Vec3()
        : Vec<Type, 3>()
    {}

    inline Vec3(Type x, Type y, Type z)
        : Vec<Type, 3>({x, y, z})
    {}

public:
    inline const Type &x() const
    {
        return (*this)[0];
    }
    inline Type &x()
    {
        return (*this)[0];
    }

    inline const Type &y() const
    {
        return (*this)[1];
    }
    inline Type &y()
    {
        return (*this)[1];
    }

    inline const Type &z() const
    {
        return (*this)[2];
    }
    inline Type &z()
    {
        return (*this)[2];
    }
};

typedef Vec2<double> Vec2d;
typedef Vec2<int> Vec2i;
typedef Vec2<unsigned int> Vec2u;

typedef Vec3<double> Vec3d;
typedef Vec3<int> Vec3i;
typedef Vec3<unsigned int> Vec3u;

#endif /* VEC_H_ */
