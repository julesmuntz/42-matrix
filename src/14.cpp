#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        float fov;
        std::cout << "Enter FOV angle in degrees: ";
        std::cin >> fov;

        std::ofstream file("matrix_display/proj");
        if (file.is_open())
        {
            file << projection(fov, 1, 0.01f, 10);
            std::cout << "\nMatrix generated with FOV = " << fov << " degrees" << std::endl;
            std::cout << "\nEnter these commands to view the matrix:" << std::endl
                      << "-\tcd matrix_display/" << std::endl
                      << "-\t./display" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
