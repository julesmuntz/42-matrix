#pragma once

#include "Vector.hpp"

template <typename K>
class Matrix
{
public:
    std::vector<std::vector<K>> mat;

    Matrix<K>()
    {
    }
    ~Matrix<K>()
    {
    }
    Matrix<K>(const Matrix<K> &other) : mat(other.mat)
    {
    }
    Matrix<K>(std::vector<std::vector<K>> mat)
    {
        this->mat = mat;
        for (size_t i = 0; i < mat.size(); i++)
            if (mat[i].size() != mat[0].size())
                throw std::invalid_argument("Matrix must be rectangular");
    }

    Matrix<K> &operator=(const Matrix<K> &other)
    {
        mat = other.mat;
        return *this;
    }
    Matrix<K> &operator+=(const Matrix<K> &other)
    {
        for (size_t i = 0; i < mat.size(); i++)
            for (size_t j = 0; j < mat[i].size(); j++)
                mat[i][j] += other.mat[i][j];
        return *this;
    }
    Matrix<K> &operator-=(const Matrix<K> &other)
    {
        for (size_t i = 0; i < mat.size(); i++)
            for (size_t j = 0; j < mat[i].size(); j++)
                mat[i][j] -= other.mat[i][j];
        return *this;
    }
    Matrix<K> &operator*=(K a)
    {
        for (size_t i = 0; i < mat.size(); i++)
            for (size_t j = 0; j < mat[i].size(); j++)
                mat[i][j] *= a;
        return *this;
    }
    Matrix<K> &operator+(const Matrix<K> &mat)
    {
        return *this += mat;
    }
    Matrix<K> &operator-(const Matrix<K> &mat)
    {
        return *this -= mat;
    }
    Matrix<K> &operator*(K a)
    {
        return *this *= a;
    }

    Matrix<K> add(Matrix<K> mat)
    {
        return *this += mat;
    }
    Matrix<K> sub(Matrix<K> mat)
    {
        return *this -= mat;
    }
    Matrix<K> scl(K a)
    {
        return *this *= a;
    }

    Vector<K> mul_vec(Vector<K> vec) const
    {
        std::vector<K> result;
        for (size_t i = 0; i < this->mat.size(); i++)
        {
            K sum = 0;
            for (size_t j = 0; j < vec.vec.size(); j++)
                sum += this->mat[i][j] * vec.vec[j];
            result.push_back(sum);
        }
        return Vector<K>(result);
    }
    Matrix<K> mul_mat(Matrix<K> mat) const
    {
        std::vector<std::vector<K>> result;
        for (size_t i = 0; i < this->mat.size(); i++)
        {
            std::vector<K> row;
            for (size_t j = 0; j < mat.mat[0].size(); j++)
            {
                K sum = 0;
                for (size_t k = 0; k < mat.mat.size(); k++)
                    sum += this->mat[i][k] * mat.mat[k][j];
                row.push_back(sum);
            }
            result.push_back(row);
        }
        return Matrix<K>(result);
    }
    Matrix<K> trace() const
    {
        is_square(*this);
        std::vector<std::vector<K>> result;
        K sum = 0;
        for (size_t i = 0; i < this->mat.size(); i++)
            sum += this->mat[i][i];
        return Matrix<K>({{sum}});
    }
    Matrix<K> transpose() const
    {
        std::vector<std::vector<K>> result;
        for (size_t i = 0; i < this->mat[0].size(); i++)
        {
            std::vector<K> row;
            for (size_t j = 0; j < this->mat.size(); j++)
                row.push_back(this->mat[j][i]);
            result.push_back(row);
        }
        return Matrix<K>(result);
    }
};

template <typename K>
std::ostream &operator<<(std::ostream &os, const Matrix<K> &mat)
{
    os << "[";
    for (size_t i = 0; i < mat.mat.size(); i++)
    {
        os << "[";
        for (size_t j = 0; j < mat.mat[i].size(); j++)
        {
            os << mat.mat[i][j];
            if (j < mat.mat[i].size() - 1)
                os << ", ";
        }
        os << "]";
        if (i < mat.mat.size() - 1)
            os << "," << std::endl
               << " ";
    }
    os << "]";
    return os;
}
