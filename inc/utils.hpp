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
    is_same_dimension(u, v);
    return u.dot(v) / (u.norm() * v.norm());
}

template <typename K>
Vector<K> cross_product(const Vector<K> &u, const Vector<K> &v)
{
    if (u.vec.size() != 3 || v.vec.size() != 3)
        throw typename Vector<K>::exception("Vectors must be 3-dimensional");
    Vector<K> result;
    result.vec.push_back(u.vec[1] * v.vec[2] - u.vec[2] * v.vec[1]);
    result.vec.push_back(u.vec[2] * v.vec[0] - u.vec[0] * v.vec[2]);
    result.vec.push_back(u.vec[0] * v.vec[1] - u.vec[1] * v.vec[0]);
    return result;
}

template <typename K>
void is_square(const Matrix<K> &mat)
{
    if (mat.mat.size() != mat.mat[0].size())
        throw typename Matrix<K>::exception("Matrix must be square");
}

template <typename K>
void is_same_dimension(const Vector<K> &u, const Vector<K> &v)
{
    if (u.vec.size() != v.vec.size())
        throw typename Vector<K>::exception("Vectors must be of the same dimension");
}

Matrix<float> projection(float fov, float ratio, float near, float far)
{
    Matrix<float> result;
    float top = near * tan(fov * M_PI / 180 / 2);
    float right = top * ratio;
    float bottom = -top;
    float left = -right;
    result.mat.push_back({2 * near / (right - left), 0, 0, -near * (right + left) / (right - left)});
    result.mat.push_back({0, 2 * near / (top - bottom), 0, -near * (top + bottom) / (top - bottom)});
    result.mat.push_back({0, 0, -(far + near) / (far - near), 2 * far * near / (near - far)});
    result.mat.push_back({0, 0, -1, 0});
    return result.transpose();
}
