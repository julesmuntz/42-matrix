#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

int main()
{
    try
    {
        {
            Vector<float> u({0., 0.});
            const Vector<float> v({1., 1.});
            print(u.dot(v));
        }
        {
            Vector<float> u({1., 1.});
            const Vector<float> v({1., 1.});
            print(u.dot(v));
        }
        {
            Vector<float> u({-1., 6.});
            const Vector<float> v({3., 2.});
            print(u.dot(v));
        }

        std::cout << "\n--- Dot Product Tests ---\n";
        print(Vector<float>({0, 0}).dot(Vector<float>({0, 0})));
        print(Vector<float>({1, 0}).dot(Vector<float>({0, 0})));
        print(Vector<float>({1, 0}).dot(Vector<float>({1, 0})));
        print(Vector<float>({1, 0}).dot(Vector<float>({0, 1})));
        print(Vector<float>({1, 1}).dot(Vector<float>({1, 1})));
        print(Vector<float>({4, 2}).dot(Vector<float>({2, 1})));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
