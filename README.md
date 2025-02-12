Using g++ for compiling as below:

g++ -march=native .\testeCalculo.cpp -ffast-math -o testeCalculo
g++ -std=c++17 -O3 -march=native -flto -ffast-math testeCalculo.cpp -o testeCalculo
