#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            const Vector<float> u({0., 0., 1.});
            const Vector<float> v({1., 0., 0.});
            cross_product(u, v).print(std::cout);
        }
        {
            const Vector<float> u({1., 2., 3.});
            const Vector<float> v({4., 5., 6.});
            cross_product(u, v).print(std::cout);
        }
        {
            const Vector<float> u({4., 2., -3.});
            const Vector<float> v({-2., -5., 16.});
            cross_product(u, v).print(std::cout);
        }

        std::cout << "\n--- Cross Product Tests ---\n";
        cross_product(Vector<float>({0, 0, 0}), Vector<float>({0, 0, 0})).print(std::cout);
        cross_product(Vector<float>({1, 0, 0}), Vector<float>({0, 0, 0})).print(std::cout);
        cross_product(Vector<float>({1, 0, 0}), Vector<float>({0, 1, 0})).print(std::cout);
        cross_product(Vector<float>({8, 7, -4}), Vector<float>({3, 2, 1})).print(std::cout);
        cross_product(Vector<float>({1, 1, 1}), Vector<float>({0, 0, 0})).print(std::cout);
        cross_product(Vector<float>({1, 1, 1}), Vector<float>({1, 1, 1})).print(std::cout);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
