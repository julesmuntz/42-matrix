#include "Vector.hpp"
#include "Matrix.hpp"

int main()
{
    {
        Vector<float> u = Vector<float>({2., 3.});
        const Vector<float> v = Vector<float>({5., 7.});
        u.add(v);
        std::cout << "Addition of 2 vectors:" << std::endl << u << std::endl << std::endl;
    }
    {
        Vector<float> u = Vector<float>({2., 3.});
        const Vector<float> v = Vector<float>({5., 7.});
        u.sub(v);
        std::cout << "Subtraction of 2 vectors:" << std::endl << u << std::endl << std::endl;
    }
    {
        Vector<float> u = Vector<float>({2., 3.});
        u.scl(2.);
        std::cout << "Scaling of a vector:" << std::endl << u << std::endl << std::endl;
    }

    {
        Matrix<float> u = Matrix<float>({{1., 2.}, {3., 4.}});
        const Matrix<float> v = Matrix<float>({{7., 4.}, {-2., 2.}});
        u.add(v);
        std::cout << "Addition of 2 matrices:" << std::endl << u << std::endl << std::endl;
    }
    {
        Matrix<float> u = Matrix<float>({{1., 2.}, {3., 4.}});
        const Matrix<float> v = Matrix<float>({{7., 4.}, {-2., 2.}});
        u.sub(v);
        std::cout << "Subtraction of 2 matrices:" << std::endl << u << std::endl << std::endl;
    }
    {
        Matrix<float> u = Matrix<float>({{1., 2.}, {3., 4.}});
        u.scl(2.);
        std::cout << "Scaling of a matrix:" << std::endl << u << std::endl << std::endl;
    }
    return 0;
}