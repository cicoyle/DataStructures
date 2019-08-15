#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <chrono>
#include <stdlib.h>
using std::cout;
using std::endl;

long long int fib(int n) {
    int fnow = 0, fnext = 1, tempf;
    while(--n>0){
        tempf = fnow + fnext;
        fnow = fnext;
        fnext = tempf;
    }
    return fnext;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    fib(1000);

    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;

    cout << endl << "Elapsed time:  " << elapsed.count() << "s\n";
}