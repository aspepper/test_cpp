Using g++ for compiling as below:

g++ -march=native .\testeCalculo.cpp -ffast-math -o testeCalculo

or

g++ -std=c++17 -O3 -march=native -flto -ffast-math testeCalculo.cpp -o testeCalculo


Change line 11 in testeCalculo.cpp by system("cls"); on Windows system instead system("clear");. The "clear" command works only on Linux and MacOS.
