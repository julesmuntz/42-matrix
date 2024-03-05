#include "Vector.hpp"
#include "Matrix.hpp"

int main()
{
    {
        const Matrix<float> u = Matrix<float>({{1., 0.}, {0., 1.}});
        const Vector<float> v = Vector<float>({4., 2.});
        std::cout << u.mul_vec(v) << std::endl << std::endl;
    }
    {
        const Matrix<float> u = Matrix<float>({{2., 0.}, {0., 2.}});
        const Vector<float> v = Vector<float>({4., 2.});
        std::cout << u.mul_vec(v) << std::endl << std::endl;
    }
    {
        const Matrix<float> u = Matrix<float>({{2., -2.}, {-2., 2.}});
        const Vector<float> v = Vector<float>({4., 2.});
        std::cout << u.mul_vec(v) << std::endl << std::endl;
    }

    {
        const Matrix<float> u = Matrix<float>({{1., 0.}, {0., 1.}});
        const Matrix<float> v = Matrix<float>({{1., 0.}, {0., 1.}});
        std::cout << u.mul_mat(v) << std::endl << std::endl;
    }
    {
        const Matrix<float> u = Matrix<float>({{1., 0.}, {0., 1.}});
        const Matrix<float> v = Matrix<float>({{2., 1.}, {4., 2.}});
        std::cout << u.mul_mat(v) << std::endl << std::endl;
    }
    {
        const Matrix<float> u = Matrix<float>({{3., -5.}, {6., 8.}});
        const Matrix<float> v = Matrix<float>({{2., 1.}, {4., 2.}});
        std::cout << u.mul_mat(v) << std::endl << std::endl;
    }
    return 0;
}
