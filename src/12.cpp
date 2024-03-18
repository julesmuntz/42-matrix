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
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
