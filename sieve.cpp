/*
g++ -std=c++17 -O3 -march=native -flto -ffast-math sieve.cpp -o sieve
*/

#include <iostream>
#include <vector>
#include <chrono>

int main() {
    // Limpa a tela
    system("clear");

    const int LIMIT = 100000000; // 10^8
    std::vector<bool> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;

    auto start = std::chrono::high_resolution_clock::now();

    for (int p = 2; p * p <= LIMIT; ++p) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= LIMIT; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    int count = 0;
    for (bool v : is_prime) if (v) ++count;

    std::cout << "C++ Sieve: " << ms << " ms – Primes: " << count << "\n";
    return 0;
}