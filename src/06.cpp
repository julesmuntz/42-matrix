#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    {
        const Vector<float> u = Vector<float>({0., 0., 1.});
        const Vector<float> v = Vector<float>({1., 0., 0.});
        std::cout << cross_product(u, v) << std::endl << std::endl;
    }
    {
        const Vector<float> u = Vector<float>({1., 2., 3.});
        const Vector<float> v = Vector<float>({4., 5., 6.});
        std::cout << cross_product(u, v) << std::endl << std::endl;
    }
    {
        const Vector<float> u = Vector<float>({4., 2., -3.});
        const Vector<float> v = Vector<float>({-2., -5., 16.});
        std::cout << cross_product(u, v) << std::endl << std::endl;
    }
    return 0;
}
