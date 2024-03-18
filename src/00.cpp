#include "Vector.hpp"
#include "Matrix.hpp"

int main()
{
    try
    {
        {
            Vector<float> u({2., 3.});
            const Vector<float> v({5., 7.});
            u.add(v);
            u.print(std::cout);
        }
        {
            Vector<float> u({2., 3.});
            const Vector<float> v({5., 7.});
            u.sub(v);
            u.print(std::cout);
        }
        {
            Vector<float> u({2., 3.});
            u.scl(2.);
            u.print(std::cout);
        }

        {
            Matrix<float> u({{1., 2.}, {3., 4.}});
            const Matrix<float> v({{7., 4.}, {-2., 2.}});
            u.add(v);
            u.print(std::cout);
        }
        {
            Matrix<float> u({{1., 2.}, {3., 4.}});
            const Matrix<float> v({{7., 4.}, {-2., 2.}});
            u.sub(v);
            u.print(std::cout);
        }
        {
            Matrix<float> u({{1., 2.}, {3., 4.}});
            u.scl(2.);
            u.print(std::cout);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
