#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            Vector<float> u({0., 0.});
            const Vector<float> v({1., 1.});
            std::cout << u.dot(v) << std::endl;
        }
        {
            Vector<float> u({1., 1.});
            const Vector<float> v({1., 1.});
            std::cout << u.dot(v) << std::endl;
        }
        {
            Vector<float> u({-1., 6.});
            const Vector<float> v({3., 2.});
            std::cout << u.dot(v) << std::endl;
        }

        std::cout << "\n--- Dot Product Tests ---\n";
        std::cout << Vector<float>({0, 0}).dot(Vector<float>({0, 0})) << std::endl;
        std::cout << Vector<float>({1, 0}).dot(Vector<float>({0, 0})) << std::endl;
        std::cout << Vector<float>({1, 0}).dot(Vector<float>({1, 0})) << std::endl;
        std::cout << Vector<float>({1, 0}).dot(Vector<float>({0, 1})) << std::endl;
        std::cout << Vector<float>({1, 1}).dot(Vector<float>({1, 1})) << std::endl;
        std::cout << Vector<float>({4, 2}).dot(Vector<float>({2, 1})) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
