#include <random>
#include <chrono>
#include <iostream>
#include "./Matrix/Matrix.hpp"
#include "./MatrixView/MatrixV.hpp"
#include <iostream>

int main()
{
    std::cout << "Matrix Tests" << std::endl;
    {
        Matrix m(10, 4);
        std::cout << "(" << m.rows() << ", " << m.cols() << ")\n"; // prints (10, 4)
        m(0, 0) = 1.4;
        std::cout << m(0, 0) << "\n"; // prints 1.4
        std::cout << m(1, 1) << "\n"; // undefined behaviour – can be anything
        try { m(11, 0); /*undefined behaviour – no bounds checks in release mode*/ }
        catch(std::overflow_error &e) { std::cerr << e.what() << std::endl; }
        const auto& m2(m);
        std::cout << m2(0, 0) << "\n"; // prints 1.4
        Matrix m3(m);
        std::cout << m3(0, 0) << "\n"; // prints 1.4
        m3(0, 0) = 42.0;
        std::cout << m3(0, 0) << ", " << m(0, 0) << "\n"; // prints 42.0, 1.4
        Matrix m4(std::move(m3)); // no data is copied, using original m3 is undefined
        std::cout << m4(0, 0) << "\n"; // prints 42
        m4 = m;
        std::cout << m4(0, 0) << "\n"; // prints 1.4
        m4(0, 0) = 3.0;
        std::cout << m4(0, 0) << ", " << m(0, 0) << "\n"; // prints 3.0, 1.4
        Matrix m5(2, 3);
        m5 = std::move(m4); // move assign – no copies made
        std::cout << m5(0, 0) << "\n"; // prints 3
        std::cout << m4(0, 0) << "\n"; // undefined behaviour – should never happen
        Matrix m6(2, 3);
        m6 = std::move(m5); // move assign – no copies made
        Matrix m7(2, 3, 42.0); // construct with initialiser value
        std::cout << m7(1, 1) << "\n"; // prints 42
    }
    std::cout << "\nMatrixView Tests" << std::endl;
    {
        Matrix m(10, 4);
        m(2, 3) = 1.4;
        MatrixView v(m, 1, 2, 2, 2); // start_row, start_col, num_rows, num_cols
        std::cout << v(1, 1) << "\n"; // prints 1.4
        std::cout << "(" << v.rows() << ", " << v.cols() << ")\n"; // prints (2, 2)
        v(1, 0) = 42.2;
        std::cout << m(2, 2) << "\n"; // prints 42
        Matrix m2 = v;
        std::cout << m2(1, 1) << ", " << m2(1, 0) << "\n"; // prints 1.4, 42.2
        std::cout << "(" << m2.rows() << ", " << m2.cols() << ")\n"; // prints (2, 2)
        auto p_m3 = std::make_unique<Matrix>(m); // dynamically-allocated copy of m
        MatrixView v3(*p_m3, 1, 2, 2, 2); // create a view
        p_m3 = nullptr; // destroy p_m3
        std::cout << v3(1, 1) << "\n"; // still prints 1.4 – data preserved in the view
    }
    std::cout << "Stress Case" << std::endl;
    {
        constexpr int N = 20000;
        constexpr int M = 4000;
        // create a big matrix of NxN
        Matrix m(N, N);
        std::default_random_engine eng(1234);
        std::uniform_real_distribution<double> dist(-1.0, 1.0);
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                m(i, j) = dist(eng);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto t_init = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() * 1e-3;
        double sum = 0.0;
        // calculate Frobenius norms of rectangular tiles of different sizes
        std::uniform_int_distribution<int> startdist(0, N - M), spandist(1, M);
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; ++i)
        {
            int starti = startdist(eng);
            int startj = startdist(eng);
            int spani = spandist(eng);
            int spanj = spandist(eng);
            MatrixView mv(m, starti, startj, spani, spanj);
            // use the result to avoid aggressive compiler to optimise out the loop.
            sum += frobenius_norm(mv);
        }
        stop = std::chrono::high_resolution_clock::now();
        auto t_comp =
        std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() * 1e-3;
        std::cout << "init time = " << t_init << "ms\n"<< "run time = " << t_comp << "ms\n"
        << "sum = " << sum << "\n";
    }
}

