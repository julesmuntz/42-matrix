#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            const Matrix<float> u({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
            auto inv = u.inverse();
            if (inv)
                inv->print(std::cout);
        }
        {
            const Matrix<float> u({{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}});
            auto inv = u.inverse();
            if (inv)
                inv->print(std::cout);
        }
        {
            const Matrix<float> u({{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}});
            auto inv = u.inverse();
            if (inv)
                inv->print(std::cout);
        }

        std::cout << "\n--- Inverse Tests ---\n";
        Matrix<float> a({{1, 0}, {0, 1}});
        auto ia = a.inverse();
        if (ia)
            ia->print(std::cout);
        Matrix<float> b({{2, 0}, {0, 2}});
        auto ib = b.inverse();
        if (ib)
            ib->print(std::cout);
        Matrix<float> c({{0.5, 0}, {0, 0.5}});
        auto ic = c.inverse();
        if (ic)
            ic->print(std::cout);
        Matrix<float> d({{0, 1}, {1, 0}});
        auto id = d.inverse();
        if (id)
            id->print(std::cout);
        Matrix<float> e({{1, 2}, {3, 4}});
        auto ie = e.inverse();
        if (ie)
            ie->print(std::cout);
        Matrix<float> f({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
        auto if_ = f.inverse();
        if (if_)
            if_->print(std::cout);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
