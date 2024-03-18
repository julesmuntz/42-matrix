#include "Vector.hpp"
#include "Matrix.hpp"

int main()
{
    try
    {
        {
            const Matrix<float> u({{1., 0.}, {0., 1.}});
            const Vector<float> v({4., 2.});
            u.mul_vec(v).print(std::cout);
        }
        {
            const Matrix<float> u({{2., 0.}, {0., 2.}});
            const Vector<float> v({4., 2.});
            u.mul_vec(v).print(std::cout);
        }
        {
            const Matrix<float> u({{2., -2.}, {-2., 2.}});
            const Vector<float> v({4., 2.});
            u.mul_vec(v).print(std::cout);
        }

        {
            const Matrix<float> u({{1., 0.}, {0., 1.}});
            const Matrix<float> v({{1., 0.}, {0., 1.}});
            u.mul_mat(v).print(std::cout);
        }
        {
            const Matrix<float> u({{1., 0.}, {0., 1.}});
            const Matrix<float> v({{2., 1.}, {4., 2.}});
            u.mul_mat(v).print(std::cout);
        }
        {
            const Matrix<float> u({{3., -5.}, {6., 8.}});
            const Matrix<float> v({{2., 1.}, {4., 2.}});
            u.mul_mat(v).print(std::cout);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
