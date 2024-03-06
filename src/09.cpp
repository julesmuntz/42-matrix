#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            const Matrix<float> u = Matrix<float>({{1., 2.}, {3., 4.}, {5., 6.}});
            std::cout << "Before: " << std::endl << u << std::endl << std::endl;
            std::cout << "After:  " << std::endl << u.transpose() << std::endl << "________________________" << std::endl << std::endl;
        }
        {
            const Matrix<float> u = Matrix<float>({{1., 2., 3.}, {4., 5., 6.}});
            std::cout << "Before: " << std::endl << u << std::endl << std::endl;
            std::cout << "After:  " << std::endl << u.transpose() << std::endl << "________________________" << std::endl << std::endl;
        }
        {
            const Matrix<float> u = Matrix<float>({{1., 2.}, {3., 4.}});
            std::cout << "Before: " << std::endl << u << std::endl << std::endl;
            std::cout << "After:  " << std::endl << u.transpose() << std::endl << std::endl << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
