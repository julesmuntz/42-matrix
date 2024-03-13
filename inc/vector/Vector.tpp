#include "Vector.hpp"

template <typename K>
Vector<K>::Vector()
{
}

template <typename K>
Vector<K>::~Vector()
{
}

template <typename K>
Vector<K>::Vector(const Vector<K> &other) : vec(other.vec)
{
}

template <typename K>
Vector<K>::Vector(const std::vector<K> &vec) : vec(vec)
{
}

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
    return (os);
}

template <typename K>
Vector<K> &Vector<K>::operator=(const Vector<K> &other)
{
    vec = other.vec;
    return (*this);
}

template <typename K>
Vector<K> &Vector<K>::operator+=(const Vector<K> &other)
{
    for (size_t i = 0; i < vec.size(); i++)
        vec[i] += other.vec[i];
    return (*this);
}

template <typename K>
Vector<K> &Vector<K>::operator-=(const Vector<K> &other)
{
    for (size_t i = 0; i < vec.size(); i++)
        vec[i] -= other.vec[i];
    return (*this);
}

template <typename K>
Vector<K> &Vector<K>::operator*=(const K a)
{
    for (size_t i = 0; i < vec.size(); i++)
        vec[i] *= a;
    return (*this);
}

template <typename K>
Vector<K> &Vector<K>::operator+(const Vector<K> &vec)
{
    return (*this += vec);
}

template <typename K>
Vector<K> &Vector<K>::operator-(const Vector<K> &vec)
{
    return (*this -= vec);
}

template <typename K>
Vector<K> &Vector<K>::operator*(const K a)
{
    return (*this *= a);
}

template <typename K>
Vector<K> &Vector<K>::add(const Vector<K> &vec)
{
    return (*this += vec);
}

template <typename K>
Vector<K> &Vector<K>::sub(const Vector<K> &vec)
{
    return (*this -= vec);
}

template <typename K>
Vector<K> &Vector<K>::scl(const K a)
{
    return (*this *= a);
}

template <typename K>
K Vector<K>::dot(Vector<K> vec) const
{
    is_same_dimension(*this, vec);
    K result = 0;
    for (size_t i = 0; i < this->vec.size(); i++)
        result += this->vec[i] * vec.vec[i];
    return (result);
}

template <typename K>
float Vector<K>::norm_1(void) const
{
    float result = 0;
    for (size_t i = 0; i < this->vec.size(); i++)
        result += std::abs(this->vec[i]);
    return (result);
}

template <typename K>
float Vector<K>::norm(void) const
{
    float result = 0;
    for (size_t i = 0; i < this->vec.size(); i++)
        result += this->vec[i] * this->vec[i];
    return (pow(result, 0.5));
}

template <typename K>
float Vector<K>::norm_inf(void) const
{
    float result = 0;
    for (size_t i = 0; i < this->vec.size(); i++)
        result = std::max(result, std::abs(this->vec[i]));
    return (result);
}
