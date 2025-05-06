/*
g++ -std=c++17 -O3 -march=native -flto -ffast-math matrix_mul.cpp -o matrix_mul
*/

#include <iostream>
#include <vector>
#include <chrono>
#ifdef _OPENMP
#include <omp.h>
#endif

int main() {
    // Limpa a tela
    system("clear");

    const int N = 1000; // ajuste conforme desejar
    std::vector<std::vector<double>> A(N, std::vector<double>(N, 1.0));
    std::vector<std::vector<double>> B(N, std::vector<double>(N, 2.0));
    std::vector<std::vector<double>> C(N, std::vector<double>(N, 0.0));

    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            double sum = 0.0;
            for (int k = 0; k < N; ++k) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "C++ Matrix Mul: " << ms << " ms\n";
    // Para assegurar que C não seja otimizado para fora:
    std::cout << "C[0][0] = " << C[0][0] << "\n";
    return 0;
}
