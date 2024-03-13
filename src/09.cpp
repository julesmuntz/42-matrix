#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            const Matrix<float> u({{1., 2.}, {3., 4.}, {5., 6.}});
            std::cout << u.transpose() << std::endl << std::endl;
        }
        {
            const Matrix<float> u({{1., 2., 3.}, {4., 5., 6.}});
            std::cout << u.transpose() << std::endl << std::endl;
        }
        {
            const Matrix<float> u({{1., 2.}, {3., 4.}});
            std::cout << u.transpose() << std::endl << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
