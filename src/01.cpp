#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        const Vector<float> e1({1., 0., 0.});
        const Vector<float> e2({0., 1., 0.});
        const Vector<float> e3({0., 0., 1.});

        const Vector<float> v1({1., 2., 3.});
        const Vector<float> v2({0., 10., -100.});

        linear_combination<float>({e1, e2, e3}, {10., -2., 0.5}).print(std::cout);
        linear_combination<float>({v1, v2}, {10., -2.}).print(std::cout);

        std::cout << "\n--- Linear Combination Tests ---\n";
        linear_combination<float>({Vector<float>({-42, 42})}, {-1}).print(std::cout);
        linear_combination<float>({Vector<float>({-42}), Vector<float>({-42}), Vector<float>({-42})}, {-1, 1, 0}).print(std::cout);
        linear_combination<float>({Vector<float>({-42, 42}), Vector<float>({1, 3}), Vector<float>({10, 20})}, {1, -10, -1}).print(std::cout);
        linear_combination<float>({Vector<float>({-42, 100, -69.5}), Vector<float>({1, 3, 5})}, {1, -10}).print(std::cout);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
