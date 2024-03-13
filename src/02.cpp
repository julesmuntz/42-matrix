#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    std::cout << lerp(0., 1., 0.) << std::endl << std::endl;
    std::cout << lerp(0., 1., 1.) << std::endl << std::endl;
    std::cout << lerp(0., 1., 0.5) << std::endl << std::endl;
    std::cout << lerp(21., 42., 0.3) << std::endl << std::endl;
    std::cout << lerp(Vector<float>({2., 1.}), Vector<float>({4., 2.}), 0.3) << std::endl << std::endl;
    std::cout << lerp(Matrix<float>({{2., 1.}, {3., 4.}}), Matrix<float>({{20., 10.}, {30., 40.}}), 0.5) << std::endl << std::endl;
    return 0;
}
