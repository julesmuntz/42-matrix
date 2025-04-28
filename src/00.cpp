#include "Vector.hpp"
#include "Matrix.hpp"

int main()
{
    try
    {
        {
            Vector<float> u({2., 3.});
            const Vector<float> v({5., 7.});
            u.add(v);
            u.print(std::cout);
        }
        {
            Vector<float> u({2., 3.});
            const Vector<float> v({5., 7.});
            u.sub(v);
            u.print(std::cout);
        }
        {
            Vector<float> u({2., 3.});
            u.scl(2.);
            u.print(std::cout);
        }

        {
            Matrix<float> u({{1., 2.}, {3., 4.}});
            const Matrix<float> v({{7., 4.}, {-2., 2.}});
            u.add(v);
            u.print(std::cout);
        }
        {
            Matrix<float> u({{1., 2.}, {3., 4.}});
            const Matrix<float> v({{7., 4.}, {-2., 2.}});
            u.sub(v);
            u.print(std::cout);
        }
        {
            Matrix<float> u({{1., 2.}, {3., 4.}});
            u.scl(2.);
            u.print(std::cout);
        }

        std::cout << "\n--- Add, Subtract and Scale (Multiply) Tests ---\n";

        std::cout << "\n- Add -\n";
        Vector<float> v1({0, 0});
        Vector<float> v2({0, 0});
        v1.add(v2);
        v1.print(std::cout);
        Vector<float> v3({1, 0});
        Vector<float> v4({0, 1});
        v3.add(v4);
        v3.print(std::cout);
        Vector<float> v5({1, 1});
        Vector<float> v6({1, 1});
        v5.add(v6);
        v5.print(std::cout);
        Vector<float> v7({21, 21});
        Vector<float> v8({21, 21});
        v7.add(v8);
        v7.print(std::cout);
        Vector<float> v9({-21, 21});
        Vector<float> v10({21, -21});
        v9.add(v10);
        v9.print(std::cout);
        Vector<float> v11({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        Vector<float> v12({9, 8, 7, 6, 5, 4, 3, 2, 1, 0});
        v11.add(v12);
        v11.print(std::cout);

        Matrix<float> m1({{0, 0}, {0, 0}});
        Matrix<float> m2({{0, 0}, {0, 0}});
        m1.add(m2);
        m1.print(std::cout);
        Matrix<float> m3({{1, 0}, {0, 1}});
        Matrix<float> m4({{0, 0}, {0, 0}});
        m3.add(m4);
        m3.print(std::cout);
        Matrix<float> m5({{1, 1}, {1, 1}});
        Matrix<float> m6({{1, 1}, {1, 1}});
        m5.add(m6);
        m5.print(std::cout);
        Matrix<float> m7({{21, 21}, {21, 21}});
        Matrix<float> m8({{21, 21}, {21, 21}});
        m7.add(m8);
        m7.print(std::cout);

        std::cout << "\n- Subtract -\n";
        Vector<float> s1({0, 0});
        Vector<float> s2({0, 0});
        s1.sub(s2);
        s1.print(std::cout);
        Vector<float> s3({1, 0});
        Vector<float> s4({0, 1});
        s3.sub(s4);
        s3.print(std::cout);
        Vector<float> s5({1, 1});
        Vector<float> s6({1, 1});
        s5.sub(s6);
        s5.print(std::cout);
        Vector<float> s7({21, 21});
        Vector<float> s8({21, 21});
        s7.sub(s8);
        s7.print(std::cout);
        Vector<float> s9({-21, 21});
        Vector<float> s10({21, -21});
        s9.sub(s10);
        s9.print(std::cout);
        Vector<float> s11({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        Vector<float> s12({9, 8, 7, 6, 5, 4, 3, 2, 1, 0});
        s11.sub(s12);
        s11.print(std::cout);

        Matrix<float> ms1({{0, 0}, {0, 0}});
        Matrix<float> ms2({{0, 0}, {0, 0}});
        ms1.sub(ms2);
        ms1.print(std::cout);
        Matrix<float> ms3({{1, 0}, {0, 1}});
        Matrix<float> ms4({{0, 0}, {0, 0}});
        ms3.sub(ms4);
        ms3.print(std::cout);
        Matrix<float> ms5({{1, 1}, {1, 1}});
        Matrix<float> ms6({{1, 1}, {1, 1}});
        ms5.sub(ms6);
        ms5.print(std::cout);
        Matrix<float> ms7({{21, 21}, {21, 21}});
        Matrix<float> ms8({{21, 21}, {21, 21}});
        ms7.sub(ms8);
        ms7.print(std::cout);

        std::cout << "\n- Scale (Multiply) -\n";
        Vector<float> mul1({0, 0});
        mul1.scl(1);
        mul1.print(std::cout);
        Vector<float> mul2({1, 0});
        mul2.scl(1);
        mul2.print(std::cout);
        Vector<float> mul3({1, 1});
        mul3.scl(2);
        mul3.print(std::cout);
        Vector<float> mul4({21, 21});
        mul4.scl(2);
        mul4.print(std::cout);
        Vector<float> mul5({42, 42});
        mul5.scl(0.5);
        mul5.print(std::cout);

        Matrix<float> mm1({{0, 0}, {0, 0}});
        mm1.scl(0);
        mm1.print(std::cout);
        Matrix<float> mm2({{1, 0}, {0, 1}});
        mm2.scl(1);
        mm2.print(std::cout);
        Matrix<float> mm3({{1, 2}, {3, 4}});
        mm3.scl(2);
        mm3.print(std::cout);
        Matrix<float> mm4({{21, 21}, {21, 21}});
        mm4.scl(0.5);
        mm4.print(std::cout);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
