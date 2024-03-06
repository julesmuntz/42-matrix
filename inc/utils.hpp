#pragma once

#include "Vector.hpp"
#include "Matrix.hpp"

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
    result.vec.push_back(u.vec[1] * v.vec[2] - u.vec[2] * v.vec[1]);
    result.vec.push_back(u.vec[2] * v.vec[0] - u.vec[0] * v.vec[2]);
    result.vec.push_back(u.vec[0] * v.vec[1] - u.vec[1] * v.vec[0]);
    return result;
}

template <typename K>
bool is_square(const Matrix<K> &mat)
{
    for (size_t i = 0; i < mat.mat.size(); i++)
        if (mat.mat[i].size() != mat.mat.size())
            return false;
    return true;
}
