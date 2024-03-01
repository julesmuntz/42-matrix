#pragma once

#include <vector>
#include <iostream>

template <typename K>
class Vector
{
public:
    std::vector<K> v;

    Vector()
    {
    }
    ~Vector()
    {
    }
    Vector(const Vector &other) : v(other.v)
    {
    }
    Vector(std::vector<K> v)
    {
        this->v = v;
    }

    Vector operator=(Vector &other)
    {
        v = other.v;
        return *this;
    }
    Vector operator+=(Vector &other)
    {
        for (size_t i = 0; i < v.size(); i++)
            v[i] += other.v[i];
        return *this;
    }
    Vector operator-=(Vector &other)
    {
        for (size_t i = 0; i < v.size(); i++)
            v[i] -= other.v[i];
        return *this;
    }
    Vector operator*=(K a)
    {
        for (size_t i = 0; i < v.size(); i++)
            v[i] *= a;
        return *this;
    }

    Vector add(Vector v)
    {
        return *this += v;
    }
    Vector sub(Vector v)
    {
        return *this -= v;
    }
    Vector scl(K a)
    {
        return *this *= a;
    }
};

template <typename K>
std::ostream &operator<<(std::ostream &os, const Vector<K> &v)
{
    os << "[";
    for (size_t i = 0; i < v.v.size(); i++)
    {
        os << v.v[i];
        if (i < v.v.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}
