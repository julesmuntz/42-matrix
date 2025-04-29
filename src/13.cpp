#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            const Matrix<float> u({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
            print(u.rank());
        }
        {
            const Matrix<float> u({{1., 2., 0., 0.}, {2., 4., 0., 0.}, {-1., 2., 1., 1.}});
            print(u.rank());
        }
        {
            const Matrix<float> u({{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}, {21., 18., 7.}});
            print(u.rank());
        }

        std::cout << "\n--- Rank Tests ---\n";
        print(Matrix<float>({{0, 0}, {0, 0}}).rank());
        print(Matrix<float>({{1, 0}, {0, 1}}).rank());
        print(Matrix<float>({{2, 0}, {0, 2}}).rank());
        print(Matrix<float>({{1, 1}, {1, 1}}).rank());
        print(Matrix<float>({{0, 1}, {1, 0}}).rank());
        print(Matrix<float>({{1, 2}, {3, 4}}).rank());
        print(Matrix<float>({{-7, 5}, {4, 6}}).rank());
        print(Matrix<float>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}).rank());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
