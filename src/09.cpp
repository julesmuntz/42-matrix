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

        std::cout << "\n--- Transpose Tests ---\n";
        Matrix<float> a({{0, 0}, {0, 0}});
        a.transpose().print(std::cout);
        Matrix<float> b({{1, 0}, {0, 1}});
        b.transpose().print(std::cout);
        Matrix<float> c({{1, 2}, {3, 4}});
        c.transpose().print(std::cout);
        Matrix<float> d({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
        d.transpose().print(std::cout);
        Matrix<float> e({{1, 2}, {3, 4}, {5, 6}});
        e.transpose().print(std::cout);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
