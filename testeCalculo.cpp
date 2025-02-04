#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdlib>  // Necessário para system("clear")
#ifdef _OPENMP
#include <omp.h>
#endif

int main() {
    // Limpa a tela
    system("clear");

    // Marca o tempo de início
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    // Realiza cálculos complexos com paralelismo
    double result = 0.0;
    #pragma omp parallel for reduction(+:result)
    for (int i = 1; i <= 10000000; ++i) {
        double i_f64 = static_cast<double>(i);
        result += std::sin(std::sqrt(i_f64)) * std::cos(i_f64) * std::tan(i_f64);
    }

    // Marca o tempo de fim
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calcula a duração em milissegundos
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Exibe o tempo de execução e o resultado do cálculo
    std::cout << "C++: Execution time: " << duration.count() << " ms" << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}
