#pragma once

#include <vector>
#include <iostream>

template <typename K>
class Matrix
{
public:
    std::vector<std::vector<K>> m;
    Matrix() {}
    ~Matrix() {}
    Matrix(const Matrix &copy)
    {
        m = copy.m;
    }
};
