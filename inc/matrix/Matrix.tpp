#include "Matrix.hpp"

template <typename K>
Matrix<K>::Matrix()
{
}

template <typename K>
Matrix<K>::~Matrix()
{
}

template <typename K>
Matrix<K>::Matrix(const Matrix<K> &other) : mat(other.mat)
{
}

template <typename K>
Matrix<K>::Matrix(const std::vector<std::vector<K>> mat) : mat(mat)
{
    for (size_t i = 0; i < mat.size(); i++)
        if (mat[i].size() != mat[0].size())
            throw typename Matrix<K>::exception("Matrix must be rectangular");
}

template <typename K>
void Matrix<K>::print(std::ostream &os) const
{
    os << "[";
    for (size_t i = 0; i < mat.size(); i++)
    {
        os << "[";
        for (size_t j = 0; j < mat[i].size(); j++)
        {
            os << mat[i][j];
            if (j < mat[i].size() - 1)
                os << ", ";
        }
        os << "]";
        if (i < mat.size() - 1)
            os << std::endl
               << " ";
    }
    os << "]" << std::endl << std::endl;
}

template <typename K>
std::ostream &operator<<(std::ostream &os, const Matrix<K> &mat)
{
    for (size_t i = 0; i < mat.mat.size(); i++)
    {
        for (size_t j = 0; j < mat.mat[i].size(); j++)
        {
            os << mat.mat[i][j];
            if (j < mat.mat[i].size() - 1)
                os << ", ";
        }
        if (i < mat.mat.size() - 1)
            os << std::endl;
    }
    return os;
}

template <typename K>
Matrix<K> &Matrix<K>::operator=(const Matrix<K> &other)
{
    mat = other.mat;
    return (*this);
}

template <typename K>
Matrix<K> &Matrix<K>::operator+=(const Matrix<K> &other)
{
    for (size_t i = 0; i < mat.size(); i++)
        for (size_t j = 0; j < mat[i].size(); j++)
            mat[i][j] += other.mat[i][j];
    return (*this);
}

template <typename K>
Matrix<K> &Matrix<K>::operator-=(const Matrix<K> &other)
{
    for (size_t i = 0; i < mat.size(); i++)
        for (size_t j = 0; j < mat[i].size(); j++)
            mat[i][j] -= other.mat[i][j];
    return (*this);
}

template <typename K>
Matrix<K> &Matrix<K>::operator*=(const K a)
{
    for (size_t i = 0; i < mat.size(); i++)
        for (size_t j = 0; j < mat[i].size(); j++)
            mat[i][j] *= a;
    return (*this);
}

template <typename K>
Matrix<K> &Matrix<K>::operator+(const Matrix<K> &mat)
{
    return (*this += mat);
}

template <typename K>
Matrix<K> &Matrix<K>::operator-(const Matrix<K> &mat)
{
    return (*this -= mat);
}

template <typename K>
Matrix<K> &Matrix<K>::operator*(const K a)
{
    return (*this *= a);
}

template <typename K>
Matrix<K> &Matrix<K>::add(const Matrix<K> &mat)
{
    return (*this += mat);
}

template <typename K>
Matrix<K> &Matrix<K>::sub(const Matrix<K> &mat)
{
    return (*this -= mat);
}

template <typename K>
Matrix<K> &Matrix<K>::scl(const K a)
{
    return (*this *= a);
}

template <typename K>
Vector<K> Matrix<K>::mul_vec(Vector<K> vec) const
{
    std::vector<K> result;
    for (size_t i = 0; i < this->mat.size(); i++)
    {
        K sum = 0;
        for (size_t j = 0; j < vec.vec.size(); j++)
            sum += this->mat[i][j] * vec.vec[j];
        result.push_back(sum);
    }
    return (Vector<K>(result));
}

template <typename K>
Matrix<K> Matrix<K>::mul_mat(Matrix<K> mat) const
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
    return (Matrix<K>(result));
}

template <typename K>
K Matrix<K>::trace() const
{
    is_square(*this);
    std::vector<std::vector<K>> result;
    K sum = 0;
    for (size_t i = 0; i < this->mat.size(); i++)
        sum += this->mat[i][i];
    return (sum);
}

template <typename K>
Matrix<K> Matrix<K>::transpose() const
{
    std::vector<std::vector<K>> result;
    for (size_t i = 0; i < this->mat[0].size(); i++)
    {
        std::vector<K> row;
        for (size_t j = 0; j < this->mat.size(); j++)
            row.push_back(this->mat[j][i]);
        result.push_back(row);
    }
    return (Matrix<K>(result));
}

template <typename K>
Matrix<K> Matrix<K>::rref(bool reduced, size_t &swap_count) const
{
    std::vector<std::vector<K>> result = this->mat;
    size_t r_index = 0;
    size_t c_index = 0;
    size_t r_size = result.size();
    size_t c_size = result[0].size();

    while (r_index < r_size && c_index < c_size)
    {
        size_t max = r_index;
        for (size_t i = (r_index + 1); i < r_size; i++)
            if (std::abs(result[i][c_index]) > std::abs(result[max][c_index]))
                max = i;
        if (max != r_index)
        {
            std::swap(result[max], result[r_index]);
            swap_count++;
        }
        if (result[r_index][c_index] == 0)
        {
            c_index++;
            continue;
        }
        K pivot = result[r_index][c_index];
        if (reduced && pivot != 0)
        {
            for (size_t j = c_index; j < c_size; j++)
                result[r_index][j] /= pivot;
        }
        for (size_t i = 0; i < r_size; i++)
        {
            if (i == r_index)
                continue;
            K factor;
            if (reduced)
                factor = result[i][c_index];
            else
                factor = result[i][c_index] / pivot;
            for (size_t k = c_index; k < c_size; k++)
                result[i][k] -= (factor * result[r_index][k]);
        }
        r_index++;
        c_index++;
    }
    return (Matrix<K>(result));
}

template <typename K>
Matrix<K> Matrix<K>::row_echelon() const
{
    size_t dummy = 0;
    return rref(true, dummy);
}

template <typename K>
K Matrix<K>::determinant() const
{
    is_square(*this);
    size_t swap_count = 0;
    Matrix<K> temp = this->rref(false, swap_count);
    K det = 1;
    for (size_t i = 0; i < temp.mat.size(); i++)
        det *= temp.mat[i][i];
    if (swap_count % 2 == 0)
        return det;
    else
        return -det;
}

template <typename K>
std::optional<Matrix<K>> Matrix<K>::inverse() const
{
    is_square(*this);
    if (this->determinant() == 0)
        return std::nullopt;
    size_t size = this->mat.size();
    std::vector<std::vector<K>> augmented(size, std::vector<K>(2 * size));
    for (size_t i = 0; i < size; i++)
    {
        std::copy(this->mat[i].begin(), this->mat[i].end(), augmented[i].begin());
        augmented[i][i + size] = 1;
    }
    Matrix<K> temp = Matrix<K>(augmented).row_echelon();
    std::vector<std::vector<K>> result(size, std::vector<K>(size));
    for (size_t i = 0; i < size; i++)
        std::copy(temp.mat[i].begin() + size, temp.mat[i].end(), result[i].begin());
    return Matrix<K>(result);
}

template <typename K>
size_t Matrix<K>::rank() const
{
    size_t result = 0;
    Matrix<K> temp = this->row_echelon();
    for (size_t i = 0; i < temp.mat.size(); i++)
    {
        for (size_t j = 0; j < temp.mat[i].size(); j++)
        {
            if (temp.mat[i][j] != 0)
            {
                result++;
                break;
            }
        }
    }
    return result;
}
