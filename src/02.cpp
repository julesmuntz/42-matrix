#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        print(lerp(0., 1., 0.));
        print(lerp(0., 1., 1.));
        print(lerp(0., 1., 0.5));
        print(lerp(21., 42., 0.3));
        lerp(Vector<float>({2., 1.}), Vector<float>({4., 2.}), 0.3).print(std::cout);
        lerp(Matrix<float>({{2., 1.}, {3., 4.}}), Matrix<float>({{20., 10.}, {30., 40.}}), 0.5).print(std::cout);

        std::cout << "\n--- Linear Interpolation (lerp) Tests ---\n";
        print(lerp(0., 1., 0.));
        print(lerp(0., 1., 1.));
        print(lerp(0., 42., 0.5));
        print(lerp(-42., 42., 0.5));
        lerp(Vector<float>({-42, 42}), Vector<float>({42, -42}), 0.5).print(std::cout);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
