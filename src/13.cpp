#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            const Matrix<float> u({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
            std::cout << u.rank() << std::endl;
        }
        {
            const Matrix<float> u({{1., 2., 0., 0.}, {2., 4., 0., 0.}, {-1., 2., 1., 1.}});
            std::cout << u.rank() << std::endl;
        }
        {
            const Matrix<float> u({{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}, {21., 18., 7.}});
            std::cout << u.rank() << std::endl;
        }

        std::cout << "\n--- Rank Tests ---\n";
        std::cout << Matrix<float>({{0, 0}, {0, 0}}).rank() << std::endl;
        std::cout << Matrix<float>({{1, 0}, {0, 1}}).rank() << std::endl;
        std::cout << Matrix<float>({{2, 0}, {0, 2}}).rank() << std::endl;
        std::cout << Matrix<float>({{1, 1}, {1, 1}}).rank() << std::endl;
        std::cout << Matrix<float>({{0, 1}, {1, 0}}).rank() << std::endl;
        std::cout << Matrix<float>({{1, 2}, {3, 4}}).rank() << std::endl;
        std::cout << Matrix<float>({{-7, 5}, {4, 6}}).rank() << std::endl;
        std::cout << Matrix<float>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}).rank() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
