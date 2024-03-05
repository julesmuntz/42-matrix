#pragma once

#include <vector>
#include <iostream>

template <typename K>
class Matrix
{
public:
    std::vector<std::vector<K>> m;

    Matrix()
    {
    }
    ~Matrix()
    {
    }
    Matrix(const Matrix &other) : m(other.m)
    {
    }
    Matrix(std::vector<std::vector<K>> m)
    {
        this->m = m;
    }

    Matrix &operator=(const Matrix &other)
    {
        m = other.m;
        return *this;
    }
    Matrix &operator+=(const Matrix &other)
    {
        for (size_t i = 0; i < m.size(); i++)
            for (size_t j = 0; j < m[i].size(); j++)
                m[i][j] += other.m[i][j];
        return *this;
    }
    Matrix &operator-=(const Matrix &other)
    {
        for (size_t i = 0; i < m.size(); i++)
            for (size_t j = 0; j < m[i].size(); j++)
                m[i][j] -= other.m[i][j];
        return *this;
    }
    Matrix &operator*=(K a)
    {
        for (size_t i = 0; i < m.size(); i++)
            for (size_t j = 0; j < m[i].size(); j++)
                m[i][j] *= a;
        return *this;
    }
    Matrix &operator+(const Matrix &m)
    {
        return *this += m;
    }
    Matrix &operator-(const Matrix &m)
    {
        return *this -= m;
    }
    Matrix &operator*(K a)
    {
        return *this *= a;
    }

    Matrix add(Matrix m)
    {
        return *this += m;
    }
    Matrix sub(Matrix m)
    {
        return *this -= m;
    }
    Matrix scl(K a)
    {
        return *this *= a;
    }
};

template <typename K>
std::ostream &operator<<(std::ostream &os, const Matrix<K> &m)
{
    os << "[";
    for (size_t i = 0; i < m.m.size(); i++)
    {
        os << "[";
        for (size_t j = 0; j < m.m[i].size(); j++)
        {
            os << m.m[i][j];
            if (j < m.m[i].size() - 1)
                os << ", ";
        }
        os << "]";
        if (i < m.m.size() - 1)
            os << "," << std::endl
               << " ";
    }
    os << "]";
    return os;
}
