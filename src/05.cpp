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
            std::cout << angle_cos(u, v) << std::endl;
        }
        {
            const Vector<float> u({1., 0.});
            const Vector<float> v({0., 1.});
            std::cout << angle_cos(u, v) << std::endl;
        }
        {
            const Vector<float> u({-1., 1.});
            const Vector<float> v({1., -1.});
            std::cout << angle_cos(u, v) << std::endl;
        }
        {
            const Vector<float> u({2., 1.});
            const Vector<float> v({4., 2.});
            std::cout << angle_cos(u, v) << std::endl;
        }
        {
            const Vector<float> u({1., 2., 3.});
            const Vector<float> v({4., 5., 6.});
            std::cout << angle_cos(u, v) << std::endl;
        }

        std::cout << "\n--- Cosine Tests ---\n";
        std::cout << angle_cos(Vector<float>({1, 0}), Vector<float>({0, 1})) << std::endl;
        std::cout << angle_cos(Vector<float>({8, 7}), Vector<float>({3, 2})) << std::endl;
        std::cout << angle_cos(Vector<float>({1, 1}), Vector<float>({1, 1})) << std::endl;
        std::cout << angle_cos(Vector<float>({4, 2}), Vector<float>({1, 1})) << std::endl;
        std::cout << angle_cos(Vector<float>({-7, 3}), Vector<float>({6, 4})) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
