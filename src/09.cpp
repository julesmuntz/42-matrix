#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            const Matrix<float> u({{1., 2.}, {3., 4.}, {5., 6.}});
            u.transpose().print(std::cout);
        }
        {
            const Matrix<float> u({{1., 2., 3.}, {4., 5., 6.}});
            u.transpose().print(std::cout);
        }
        {
            const Matrix<float> u({{1., 2.}, {3., 4.}});
            u.transpose().print(std::cout);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
