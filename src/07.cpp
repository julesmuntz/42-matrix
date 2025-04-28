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

        std::cout << "\n--- Linear Map, Matrix Multiplication Tests ---\n";
        Matrix<float> a({{0, 0}, {0, 0}});
        Vector<float> va({1, 2});
        a.mul_vec(va).print(std::cout);
        Matrix<float> b({{1, 0}, {0, 1}});
        Vector<float> vb({1, 2});
        b.mul_vec(vb).print(std::cout);
        Matrix<float> c({{1, 1}, {1, 1}});
        Vector<float> vc({4, 2});
        c.mul_vec(vc).print(std::cout);
        Matrix<float> d({{2, 0}, {0, 2}});
        Vector<float> vd({2, 1});
        d.mul_vec(vd).print(std::cout);
        Matrix<float> e({{0.5, 0}, {0, 1}});
        Vector<float> ve({4, 2});
        e.mul_vec(ve).print(std::cout);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
