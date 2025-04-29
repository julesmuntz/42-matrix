#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            const Matrix<float> u({{1., -1.}, {-1., 1.}});
            print(u.determinant());
        }
        {
            const Matrix<float> u({{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}});
            print(u.determinant());
        }
        {
            const Matrix<float> u({{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}});
            print(u.determinant());
        }
        {
            const Matrix<float> u({{8., 5., -2., 4.}, {4., 2.5, 20., 4.}, {8., 5., 1., 4.}, {28., -4., 17., 1.}});
            print(u.determinant());
        }

        std::cout << "\n--- Determinant Tests ---\n";
        print(Matrix<float>({{0, 0}, {0, 0}}).determinant());
        print(Matrix<float>({{1, 0}, {0, 1}}).determinant());
        print(Matrix<float>({{2, 0}, {0, 2}}).determinant());
        print(Matrix<float>({{1, 1}, {1, 1}}).determinant());
        print(Matrix<float>({{0, 1}, {1, 0}}).determinant());
        print(Matrix<float>({{1, 2}, {3, 4}}).determinant());
        print(Matrix<float>({{-7, 5}, {4, 6}}).determinant());
        print(Matrix<float>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}).determinant());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
