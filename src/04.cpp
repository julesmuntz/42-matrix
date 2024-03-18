#include "Vector.hpp"
#include "Matrix.hpp"

int main()
{
    try
    {
        {
            const Vector<float> u({0., 0., 0.});
            std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl << std::endl;
        }
        {
            const Vector<float> u({1., 2., 3.});
            std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl << std::endl;
        }
        {
            const Vector<float> u({-1., -2.});
            std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
