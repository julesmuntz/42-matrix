#pragma once

#include "Vector.hpp"

template <typename K>
class Matrix
{
public:
    std::vector<std::vector<K>> mat;

    Matrix<K>();
    ~Matrix<K>();
    Matrix<K>(const Matrix<K> &other);
    Matrix<K>(const std::vector<std::vector<K>> mat);

    void print(std::ostream &os) const;

    Matrix<K> &operator=(const Matrix<K> &other);
    Matrix<K> &operator+=(const Matrix<K> &other);
    Matrix<K> &operator-=(const Matrix<K> &other);
    Matrix<K> &operator*=(const K a);
    Matrix<K> &operator+(const Matrix<K> &mat);
    Matrix<K> &operator-(const Matrix<K> &mat);
    Matrix<K> &operator*(const K a);

    Matrix<K> &add(const Matrix<K> &mat);
    Matrix<K> &sub(const Matrix<K> &mat);
    Matrix<K> &scl(const K a);

    Vector<K> mul_vec(Vector<K> vec) const;
    Matrix<K> mul_mat(Matrix<K> mat) const;
    K trace() const;
    Matrix<K> transpose() const;
    Matrix<K> rref(bool reduced) const;
    Matrix<K> row_echelon() const;
    Matrix<K> non_reduced_row_echelon() const;
    K determinant() const;
    std::optional<Matrix<K>> inverse() const;
    size_t rank() const;

    class exception : public std::exception
    {
    public:
        exception(const std::string &msg) : message("\033[0;31mError: " + msg + "\033[0m") {}
        virtual const char *what() const throw() { return message.c_str(); }
        std::string message;
    };
};

#include "Matrix.tpp"
