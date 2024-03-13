#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            const Vector<float> u({1., 0.});
            const Vector<float> v({1., 0.});
            std::cout << angle_cos(u, v) << std::endl << std::endl;
        }
        {
            const Vector<float> u({1., 0.});
            const Vector<float> v({0., 1.});
            std::cout << angle_cos(u, v) << std::endl << std::endl;
        }
        {
            const Vector<float> u({-1., 1.});
            const Vector<float> v({1., -1.});
            std::cout << angle_cos(u, v) << std::endl << std::endl;
        }
        {
            const Vector<float> u({2., 1.});
            const Vector<float> v({4., 2.});
            std::cout << angle_cos(u, v) << std::endl << std::endl;
        }
        {
            const Vector<float> u({1., 2., 3.});
            const Vector<float> v({4., 5., 6.});
            std::cout << angle_cos(u, v) << std::endl << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
