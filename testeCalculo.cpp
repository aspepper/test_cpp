#include <iostream>
#include <cmath>
#include <chrono>

int main() {
    // Marca o tempo de início
    auto start = std::chrono::high_resolution_clock::now();

    // Realiza cálculos complexos
    double result = 0.0;
    for (int i = 1; i <= 1000000; ++i) {
        result += std::sin(std::sqrt(i)) * std::cos(i) * std::tan(i);
    }

    // Marca o tempo de fim
    auto end = std::chrono::high_resolution_clock::now();

    // Calcula a duração em milissegundos
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Exibe o resultado
    std::cout << "C++: Execution time: " << duration.count() << " ms" << std::endl;

    return 0;
}
