#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        // 00 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 00 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            Vector<C> u{2., 3.};
            const Vector<C> v{5., 7.};
            u.add(v);
            u.print(std::cout);
        }
        {
            Vector<C> u{2., 3.};
            const Vector<C> v{5., 7.};
            u.sub(v);
            u.print(std::cout);
        }
        {
            Vector<C> u{2., 3.};
            u.scl(5);
            u.print(std::cout);
        }

        {
            Matrix<C> u{{1., 2.}, {3., 4.}};
            const Matrix<C> v{{7., 4.}, {-2., 2.}};
            u.add(v);
            u.print(std::cout);
        }
        {
            Matrix<C> u{{1., 2.}, {3., 4.}};
            const Matrix<C> v{{7., 4.}, {-2., 2.}};
            u.sub(v);
            u.print(std::cout);
        }
        {
            Matrix<C> u{{1., 2.}, {3., 4.}};
            u.scl(2.);
            u.print(std::cout);
        }

        // 01 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 01 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            const Vector<C> e1({1., 0., 0.});
            const Vector<C> e2({0., 1., 0.});
            const Vector<C> e3({0., 0., 1.});

            const Vector<C> v1({1., 2., 3.});
            const Vector<C> v2({0., 10., -100.});

            std::list<C> coefs1{10., -2., 0.5};
            linear_combination<C>({e1, e2, e3}, coefs1).print(std::cout);

            std::list<C> coefs2{10., -2.};
            linear_combination<C>({v1, v2}, coefs2).print(std::cout);
        }

        // 02 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 02 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            std::cout << lerp(C(0.), C(1.), 0.) << std::endl << std::endl;
            std::cout << lerp(C(0.), C(1.), 1.) << std::endl << std::endl;
            std::cout << lerp(C(0.), C(1.), 0.5) << std::endl << std::endl;
            std::cout << lerp(C(21.), C(42.), 0.3) << std::endl << std::endl;
            lerp(Vector<C>({2., 1.}), Vector<C>({4., 2.}), 0.3).print(std::cout);
            lerp(Matrix<C>({{2., 1.}, {3., 4.}}), Matrix<C>({{20., 10.}, {30., 40.}}), 0.5).print(std::cout);
        }

        // 03 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 03 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            Vector<C> u({0., 0.});
            const Vector<C> v({1., 1.});
            std::cout << u.dot(v) << std::endl << std::endl;
        }
        {
            Vector<C> u({1., 1.});
            const Vector<C> v({1., 1.});
            std::cout << u.dot(v) << std::endl << std::endl;
        }
        {
            Vector<C> u({-1., 6.});
            const Vector<C> v({3., 2.});
            std::cout << u.dot(v) << std::endl << std::endl;
        }

        // 04 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 04 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            const Vector<C> u({1., 2., 3.});
            std::cout << C(u.norm_1()) << ", " << C(u.norm()) << ", " << C(u.norm_inf()) << std::endl << std::endl;
        }
        {
            const Vector<C> u({-1., -2.});
            std::cout << C(u.norm_1()) << ", " << C(u.norm()) << ", " << C(u.norm_inf()) << std::endl << std::endl;
        }
        {
            const Vector<C> u({0., 0., 0.});
            std::cout << C(u.norm_1()) << ", " << C(u.norm()) << ", " << C(u.norm_inf()) << std::endl << std::endl;
        }

        // 05 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 05 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            const Vector<C> u({1., 2., 3.});
            const Vector<C> v({4., 5., 6.});
            std::cout << C(angle_cos(u, v)) << std::endl << std::endl;
        }
        {
            const Vector<C> u({1., 0., 0.});
            const Vector<C> v({0., 1., 0.});
            std::cout << C(angle_cos(u, v)) << std::endl << std::endl;
        }
        {
            const Vector<C> u({1., 0., 0.});
            const Vector<C> v({1., 0., 0.});
            std::cout << C(angle_cos(u, v)) << std::endl << std::endl;
        }

        // 06 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 06 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            const Vector<C> u({1., 0., 0.});
            const Vector<C> v({0., 1., 0.});
            cross_product(u, v).print(std::cout);
        }
        {
            const Vector<C> u({1., 0., 0.});
            const Vector<C> v({0., 0., 1.});
            cross_product(u, v).print(std::cout);

        }
        {
            const Vector<C> u({0., 1., 0.});
            const Vector<C> v({0., 0., 1.});
            cross_product(u, v).print(std::cout);
        }

        // 07 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 07 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            const Matrix<C> u({{1., 0.}, {0., 1.}});
            const Vector<C> v({4., 2.});
            u.mul_vec(v).print(std::cout);
        }
        {
            const Matrix<C> u({{2., 0.}, {0., 2.}});
            const Vector<C> v({4., 2.});
            u.mul_vec(v).print(std::cout);
        }
        {
            const Matrix<C> u({{2., -2.}, {-2., 2.}});
            const Vector<C> v({4., 2.});
            u.mul_vec(v).print(std::cout);
        }

        {
            const Matrix<C> u({{1., 0.}, {0., 1.}});
            const Matrix<C> v({{1., 0.}, {0., 1.}});
            u.mul_mat(v).print(std::cout);
        }
        {
            const Matrix<C> u({{1., 0.}, {0., 1.}});
            const Matrix<C> v({{2., 1.}, {4., 2.}});
            u.mul_mat(v).print(std::cout);
        }
        {
            const Matrix<C> u({{3., -5.}, {6., 8.}});
            const Matrix<C> v({{2., 1.}, {4., 2.}});
            u.mul_mat(v).print(std::cout);
        }

        // 08 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 08 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            const Matrix<C> u({{1., 0.}, {0., 1.}});
            std::cout << C(u.trace()) << std::endl << std::endl;
        }
        {
            const Matrix<C> u({{2., -5., 0.}, {4., 3., 7.}, {-2., 3., 4.}});
            std::cout << C(u.trace()) << std::endl << std::endl;
        }
        {
            const Matrix<C> u({{-2., -8., 4.}, {1., -23., 4.}, {0., 6., 4.}});
            std::cout << C(u.trace()) << std::endl << std::endl;
        }

        // 09 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 09 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            const Matrix<C> u({{1., 2.}, {3., 4.}, {5., 6.}});
            u.transpose().print(std::cout);
        }
        {
            const Matrix<C> u({{1., 2., 3.}, {4., 5., 6.}});
            u.transpose().print(std::cout);
        }
        {
            const Matrix<C> u({{1., 2.}, {3., 4.}});
            u.transpose().print(std::cout);
        }

        // 10 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 10 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            const Matrix<C> u({{1., 2.}, {3., 4.}});
            u.row_echelon().print(std::cout);
        }
        {
            const Matrix<C> u({{1., 2.}, {2., 4.}});
            u.row_echelon().print(std::cout);
        }
        {
            const Matrix<C> u({{8., 5., -2., 4., 28.}, {4., 2.5, 20., 4., -4.}, {8., 5., 1., 4., 17.}});
            u.row_echelon().print(std::cout);
        }

        // 11 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 11 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            const Matrix<C> u({{1., -1.}, {-1., 1.}});
            std::cout << C(u.determinant()) << std::endl << std::endl;
        }
        {
            const Matrix<C> u({{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}});
            std::cout << C(u.determinant()) << std::endl << std::endl;
        }
        {
            const Matrix<C> u({{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}});
            std::cout << C(u.determinant()) << std::endl << std::endl;
        }
        {
            const Matrix<C> u({{8., 5., -2., 4.}, {4., 2.5, 20., 4.}, {8., 5., 1., 4.}, {28., -4., 17., 1.}});
            std::cout << C(u.determinant()) << std::endl << std::endl;
        }

        // 12 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 12 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            const Matrix<C> u({{1., 2.}, {3., 4.}});
            auto inv = u.inverse();
            if (inv)
                inv->print(std::cout);
        }
        {
            const Matrix<C> u({{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}});
            auto inv = u.inverse();
            if (inv)
                inv->print(std::cout);
        }
        {
            const Matrix<C> u({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
            auto inv = u.inverse();
            if (inv)
                inv->print(std::cout);
        }

        // 13 ////////////////////////////////////////////////////////////////
        std::cout << std::endl << "\033[38;5;75m// 13 ////////////////////////////////////////////////////////////////\033[0m" << std::endl << std::endl;
        {
            const Matrix<C> u({{1., 2.}, {3., 4.}});
            std::cout << C(u.rank()) << std::endl << std::endl;
        }
        {
            const Matrix<C> u({{1., 2., 0., 0.}, {2., 4., 0., 0.}, {-1., 2., 1., 1.}});
            std::cout << C(u.rank()) << std::endl << std::endl;
        }
        {
            const Matrix<C> u({{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}, {21., 18., 7.}});
            std::cout << C(u.rank()) << std::endl << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
