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

    Vector<K>();
    ~Vector<K>();
    Vector<K>(const Vector<K> &other);
    Vector<K>(const std::vector<K> &vec);

    Vector<K> &operator=(const Vector<K> &other);
    Vector<K> &operator+=(const Vector<K> &other);
    Vector<K> &operator-=(const Vector<K> &other);
    Vector<K> &operator*=(const K a);
    Vector<K> &operator+(const Vector<K> &vec);
    Vector<K> &operator-(const Vector<K> &vec);
    Vector<K> &operator*(const K a);

    Vector<K> &add(const Vector<K> &vec);
    Vector<K> &sub(const Vector<K> &vec);
    Vector<K> &scl(const K a);

    K dot(Vector<K> vec) const;
    float norm_1() const;
    float norm() const;
    float norm_inf() const;

    class exception : public std::exception
    {
    public:
        exception(const std::string &msg) : message("\033[0;31mError: " + msg + "\033[0m") {}
        virtual const char *what() const throw() { return message.c_str(); }
        std::string message;
    };
};

#include "Vector.tpp"
