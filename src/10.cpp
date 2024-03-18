#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            const Matrix<float> u({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
            u.row_echelon().print(std::cout);
        }
        {
            const Matrix<float> u({{1., 2.}, {3., 4.}});
            u.row_echelon().print(std::cout);
        }
        {
            const Matrix<float> u({{1., 2.}, {2., 4.}});
            u.row_echelon().print(std::cout);
        }
        {
            const Matrix<float> u({{8., 5., -2., 4., 28.}, {4., 2.5, 20., 4., -4.}, {8., 5., 1., 4., 17.}});
            u.row_echelon().print(std::cout);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
