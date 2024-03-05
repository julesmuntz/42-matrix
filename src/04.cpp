#include "Vector.hpp"
#include "Matrix.hpp"

int main()
{
    {
        const Vector<float> u = Vector<float>({0., 0., 0.});
        std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl << std::endl;
    }
    {
        const Vector<float> u = Vector<float>({1., 2., 3.});
        std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl << std::endl;
    }
    {
        const Vector<float> u = Vector<float>({-1., -2.});
        std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl << std::endl;
    }
    return 0;
}
