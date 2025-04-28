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

        std::cout << "\n--- Row-Echelon Form Tests ---\n";
        Matrix<float> a({{0, 0}, {0, 0}});
        a.row_echelon().print(std::cout);
        Matrix<float> b({{1, 0}, {0, 1}});
        b.row_echelon().print(std::cout);
        Matrix<float> c({{4, 2}, {2, 1}});
        c.row_echelon().print(std::cout);
        Matrix<float> d({{-7, 2}, {4, 8}});
        d.row_echelon().print(std::cout);
        Matrix<float> e({{1, 2}, {4, 8}});
        e.row_echelon().print(std::cout);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
