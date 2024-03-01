#pragma once

#include <vector>
#include <iostream>

template <typename K>
class Vector
{
public:
    std::vector<K> v;
    Vector() {}
    ~Vector() {}
    Vector(const Vector &copy)
    {
        v = copy.v;
    }
};
