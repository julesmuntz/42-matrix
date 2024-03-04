#include "Vector.hpp"
#include "Matrix.hpp"

int main()
{
    Vector<float> e1 = Vector<float>({1., 0., 0.});
    Vector<float> e2 = Vector<float>({0., 1., 0.});
    Vector<float> e3 = Vector<float>({0., 0., 1.});

    Vector<float> v1 = Vector<float>({1., 2., 3.});
    Vector<float> v2 = Vector<float>({0., 10., -100.});

    std::cout << "Linear combination:" << std::endl
              << Vector<float>::linear_combination({e1, e2, e3}, {10., -2., 0.5}) << std::endl
              << std::endl;

    std::cout << "Linear combination:" << std::endl
              << Vector<float>::linear_combination({v1, v2}, {10., -2.}) << std::endl
              << std::endl;
    return 0;
}