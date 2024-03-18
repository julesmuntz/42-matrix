#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        const Vector<float> e1({1., 0., 0.});
        const Vector<float> e2({0., 1., 0.});
        const Vector<float> e3({0., 0., 1.});

        const Vector<float> v1({1., 2., 3.});
        const Vector<float> v2({0., 10., -100.});

        linear_combination<float>({e1, e2, e3}, {10., -2., 0.5}).print(std::cout);
        linear_combination<float>({v1, v2}, {10., -2.}).print(std::cout);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
