#pragma once

#include <iostream>
#include "Vector.hpp"

template <typename K>
Vector<K> linear_combination(const std::list<Vector<K>> &u, const std::list<K> &coefs)
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

template <typename V>
V lerp(V u, V v, float t)
{
    return u + (v - u) * t;
}

template <typename K>
float angle_cos(const Vector<K> &u, const Vector<K> &v)
{
    return u.dot(v) / (u.norm() * v.norm());
}

template <typename K>
Vector<K> cross_product(const Vector<K> &u, const Vector<K> &v)
{
    Vector<K> result;
    result.v.push_back(u.v[1] * v.v[2] - u.v[2] * v.v[1]);
    result.v.push_back(u.v[2] * v.v[0] - u.v[0] * v.v[2]);
    result.v.push_back(u.v[0] * v.v[1] - u.v[1] * v.v[0]);
    return result;
}
