#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            const Vector<float> u({0., 0., 0.});
            std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl << std::endl;
        }
        {
            const Vector<float> u({1., 2., 3.});
            std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl << std::endl;
        }
        {
            const Vector<float> u({-1., -2.});
            std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl << std::endl;
        }

        std::cout << "\n--- Norm Tests ---\n";

        std::cout << "\n- Euclidean Norm -\n";
        print(Vector<float>({0}).norm());
        print(Vector<float>({1}).norm());
        print(Vector<float>({0, 0}).norm());
        print(Vector<float>({1, 0}).norm());
        print(Vector<float>({2, 1}).norm());
        print(Vector<float>({4, 2}).norm());
        print(Vector<float>({-4, -2}).norm());

        std::cout << "\n- Manhattan Norm -\n";
        print(Vector<float>({0}).norm_1());
        print(Vector<float>({1}).norm_1());
        print(Vector<float>({0, 0}).norm_1());
        print(Vector<float>({1, 0}).norm_1());
        print(Vector<float>({2, 1}).norm_1());
        print(Vector<float>({4, 2}).norm_1());
        print(Vector<float>({-4, -2}).norm_1());

        std::cout << "\n- Supremum Norm -\n";
        print(Vector<float>({0}).norm_inf());
        print(Vector<float>({1}).norm_inf());
        print(Vector<float>({0, 0}).norm_inf());
        print(Vector<float>({1, 0}).norm_inf());
        print(Vector<float>({2, 1}).norm_inf());
        print(Vector<float>({4, 2}).norm_inf());
        print(Vector<float>({-4, -2}).norm_inf());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
