#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            const Matrix<float> u({{1., 0.}, {0., 1.}});
            print(u.trace());
        }
        {
            const Matrix<float> u({{2., -5., 0.}, {4., 3., 7.}, {-2., 3., 4.}});
            print(u.trace());
        }
        {
            const Matrix<float> u({{-2., -8., 4.}, {1., -23., 4.}, {0., 6., 4.}});
            print(u.trace());
        }

        std::cout << "\n--- Trace Tests ---\n";
        print(Matrix<float>({{0, 0}, {0, 0}}).trace());
        print(Matrix<float>({{1, 0}, {0, 1}}).trace());
        print(Matrix<float>({{1, 2}, {3, 4}}).trace());
        print(Matrix<float>({{8, -7}, {4, 2}}).trace());
        print(Matrix<float>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}).trace());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
