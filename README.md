Using g++ for compiling as below:

g++ -march=native .\complex_calc.cpp -ffast-math -o complex_calc
g++ -std=c++17 -O3 -march=native -flto -ffast-math complex_calc.cpp -o complex_calc

g++ -march=native .\matrix_mul.cpp -ffast-math -o matrix_mul
g++ -std=c++17 -O3 -march=native -flto -ffast-math matrix_mul.cpp -o matrix_mul

g++ -march=native .\sieve.cpp -ffast-math -o sieve
g++ -std=c++17 -O3 -march=native -flto -ffast-math sieve.cpp -o sieve

g++ -march=native .\thread_spawn.cpp -ffast-math -o thread_spawn
g++ -std=c++17 -O3 -march=native -flto -ffast-math thread_spawn.cpp -o thread_spawn

Running binaries
./complex_calc
./matrix_mul
./sieve
./thread_spawn
