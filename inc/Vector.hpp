#pragma once

#include <vector>
#include <iostream>
#include <list>

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
    Vector(const std::vector<K> &v) : v(v)
    {
    }

    Vector &operator=(const Vector &other)
    {
        v = other.v;
        return *this;
    }
    Vector &operator+=(const Vector &other)
    {
        for (size_t i = 0; i < v.size(); i++)
            v[i] += other.v[i];
        return *this;
    }
    Vector &operator-=(const Vector &other)
    {
        for (size_t i = 0; i < v.size(); i++)
            v[i] -= other.v[i];
        return *this;
    }
    Vector &operator*=(K a)
    {
        for (size_t i = 0; i < v.size(); i++)
            v[i] *= a;
        return *this;
    }
    Vector &operator+(const Vector &v)
    {
        return *this += v;
    }
    Vector &operator-(const Vector &v)
    {
        return *this -= v;
    }
    Vector &operator*(K a)
    {
        return *this *= a;
    }

    Vector &add(const Vector &v)
    {
        return *this += v;
    }
    Vector &sub(const Vector &v)
    {
        return *this -= v;
    }
    Vector &scl(const K a)
    {
        return *this *= a;
    }

    static Vector linear_combination(const std::list<Vector<K>> &u, const std::list<K> &coefs)
    {
        std::list<Vector<K>> u_copy = u;
        std::list<K> coefs_copy = coefs;
        Vector<K> result = u_copy.front().scl(coefs_copy.front());
        u_copy.pop_front();
        coefs_copy.pop_front();
        while (u_copy.size())
        {
            result.add(u_copy.front().scl(coefs_copy.front()));
            u_copy.pop_front();
            coefs_copy.pop_front();
        }
        return result;
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
