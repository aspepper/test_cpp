<h2 align="center">C++ Benchmarks</h2>

## Using g++ for compiling as below:
<br />

<p>First install g++ in terminal</p>
% brew install gcc<br />
<br />

* g++ -march=native .\complex_calc.cpp -ffast-math -o complex_calc<br />
* g++ -std=c++17 -O3 -march=native -flto -ffast-math complex_calc.cpp -o complex_calc<br />
<br />

* g++ -march=native .\matrix_mul.cpp -ffast-math -o matrix_mul<br />
* g++ -std=c++17 -O3 -march=native -flto -ffast-math matrix_mul.cpp -o matrix_mul<br />
<br />

* g++ -march=native .\sieve.cpp -ffast-math -o sieve<br />
* g++ -std=c++17 -O3 -march=native -flto -ffast-math sieve.cpp -o sieve
<br />

* g++ -march=native .\thread_spawn.cpp -ffast-math -o thread_spawn<br />
* g++ -std=c++17 -O3 -march=native -flto -ffast-math thread_spawn.cpp -o thread_spawn<br />
<br />

## Running binaries
./complex_calc<br />
./matrix_mul<br />
./sieve<br />
./thread_spawn<br />
