#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            const Matrix<float> u({{1., 0.}, {0., 1.}});
            std::cout << u.trace() << std::endl << std::endl;
        }
        {
            const Matrix<float> u({{2., -5., 0.}, {4., 3., 7.}, {-2., 3., 4.}});
            std::cout << u.trace() << std::endl << std::endl;
        }
        {
            const Matrix<float> u({{-2., -8., 4.}, {1., -23., 4.}, {0., 6., 4.}});
            std::cout << u.trace() << std::endl << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
