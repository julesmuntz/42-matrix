#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        std::ofstream file("matrix_display/proj");
        if (file.is_open())
            std::cout << "Enter these commands:" << std::endl
                      << std::endl
                      << "-\tcd matrix_display/" << std::endl
                      << "-\t./display" << std::endl
                      << std::endl;
        file << projection(45, 1, 0.01f, 10);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
