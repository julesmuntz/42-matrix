#pragma once

#include <vector>
#include <iostream>
#include <list>
#include <cmath>

template <typename K>
class Vector
{
public:
    std::vector<K> vec;

    Vector<K>()
    {
    }
    ~Vector<K>()
    {
    }
    Vector<K>(const Vector<K> &other) : vec(other.vec)
    {
    }
    Vector<K>(const std::vector<K> &vec) : vec(vec)
    {
    }

    Vector<K> &operator=(const Vector<K> &other)
    {
        vec = other.vec;
        return *this;
    }
    Vector<K> &operator+=(const Vector<K> &other)
    {
        for (size_t i = 0; i < vec.size(); i++)
            vec[i] += other.vec[i];
        return *this;
    }
    Vector<K> &operator-=(const Vector<K> &other)
    {
        for (size_t i = 0; i < vec.size(); i++)
            vec[i] -= other.vec[i];
        return *this;
    }
    Vector<K> &operator*=(K a)
    {
        for (size_t i = 0; i < vec.size(); i++)
            vec[i] *= a;
        return *this;
    }
    Vector<K> &operator+(const Vector<K> &vec)
    {
        return *this += vec;
    }
    Vector<K> &operator-(const Vector<K> &vec)
    {
        return *this -= vec;
    }
    Vector<K> &operator*(K a)
    {
        return *this *= a;
    }

    Vector<K> &add(const Vector<K> &vec)
    {
        return *this += vec;
    }
    Vector<K> &sub(const Vector<K> &vec)
    {
        return *this -= vec;
    }
    Vector<K> &scl(const K a)
    {
        return *this *= a;
    }

    K dot(Vector<K> vec) const
    {
        K result = 0;
        for (size_t i = 0; i < this->vec.size(); i++)
            result += this->vec[i] * vec.vec[i];
        return result;
    }
    float norm_1() const
    {
        float result = 0;
        for (size_t i = 0; i < this->vec.size(); i++)
            result += std::abs(this->vec[i]);
        return result;
    }
    float norm() const
    {
        float result = 0;
        for (size_t i = 0; i < this->vec.size(); i++)
            result += this->vec[i] * this->vec[i];
        return pow(result, 0.5);
    }
    float norm_inf() const
    {
        float result = 0;
        for (size_t i = 0; i < this->vec.size(); i++)
            result = std::max(result, std::abs(this->vec[i]));
        return result;
    }
};

template <typename K>
std::ostream &operator<<(std::ostream &os, const Vector<K> &vec)
{
    os << "[";
    for (size_t i = 0; i < vec.vec.size(); i++)
    {
        os << vec.vec[i];
        if (i < vec.vec.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}
