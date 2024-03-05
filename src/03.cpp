#include "Vector.hpp"
#include "Matrix.hpp"

int main()
{
    {
        Vector<float> u = Vector<float>({0., 0.});
        const Vector<float> v = Vector<float>({1., 1.});
        std::cout << u.dot(v) << std::endl << std::endl;
    }
    {
        Vector<float> u = Vector<float>({1., 1.});
        const Vector<float> v = Vector<float>({1., 1.});
        std::cout << u.dot(v) << std::endl << std::endl;
    }
    {
        Vector<float> u = Vector<float>({-1., 6.});
        const Vector<float> v = Vector<float>({3., 2.});
        std::cout << u.dot(v) << std::endl << std::endl;
    }
    return 0;
}