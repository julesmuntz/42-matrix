#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    {
        const Vector<float> u = Vector<float>({1., 0.});
        const Vector<float> v = Vector<float>({1., 0.});
        std::cout << angle_cos(u, v) << std::endl << std::endl;
    }
    {
        const Vector<float> u = Vector<float>({1., 0.});
        const Vector<float> v = Vector<float>({0., 1.});
        std::cout << angle_cos(u, v) << std::endl << std::endl;
    }
    {
        const Vector<float> u = Vector<float>({-1., 1.});
        const Vector<float> v = Vector<float>({1., -1.});
        std::cout << angle_cos(u, v) << std::endl << std::endl;
    }
    {
        const Vector<float> u = Vector<float>({2., 1.});
        const Vector<float> v = Vector<float>({4., 2.});
        std::cout << angle_cos(u, v) << std::endl << std::endl;
    }
    {
        const Vector<float> u = Vector<float>({1., 2., 3.});
        const Vector<float> v = Vector<float>({4., 5., 6.});
        std::cout << angle_cos(u, v) << std::endl << std::endl;
    }
    return 0;
}
