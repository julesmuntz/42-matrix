#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    const Vector<float> e1 = Vector<float>({1., 0., 0.});
    const Vector<float> e2 = Vector<float>({0., 1., 0.});
    const Vector<float> e3 = Vector<float>({0., 0., 1.});

    const Vector<float> v1 = Vector<float>({1., 2., 3.});
    const Vector<float> v2 = Vector<float>({0., 10., -100.});

    std::cout << linear_combination<float>({e1, e2, e3}, {10., -2., 0.5}) << std::endl
              << std::endl;

    std::cout << linear_combination<float>({v1, v2}, {10., -2.}) << std::endl
              << std::endl;
    return 0;
}