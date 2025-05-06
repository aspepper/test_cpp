/*
g++ -std=c++17 -O3 -march=native -flto -ffast-math thread_spawn.cpp -o thread_spawn
*/

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void trivial_task() {
    // faz quase nada
    volatile int x = 0;
    x++;
}

int main() {
    // Limpa a tela
    system("clear");

    const int N = 1000;
    std::vector<std::thread> threads;
    threads.reserve(N);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i)
        threads.emplace_back(trivial_task);

    for (auto &t : threads)
        t.join();

    auto end = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "C++ Thread spawn (" << N << "): " << ms << " ms\n";
    return 0;
}