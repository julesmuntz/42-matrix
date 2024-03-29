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
            std::cout << u.dot(v) << std::endl << std::endl;
        }
        {
            Vector<float> u({1., 1.});
            const Vector<float> v({1., 1.});
            std::cout << u.dot(v) << std::endl << std::endl;
        }
        {
            Vector<float> u({-1., 6.});
            const Vector<float> v({3., 2.});
            std::cout << u.dot(v) << std::endl << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
