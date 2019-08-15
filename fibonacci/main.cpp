#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <chrono>
#include <stdlib.h>
using std::cout;
using std::endl;

int fib(int n){
    if(n == 0) {return	0;}
    if(n == 1) {return	1;}
    return	(fib(n-1)	+	fib(n-2));
}

int main() {

    auto start = std::chrono::high_resolution_clock::now();

    fib(50);

    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;

    cout << endl << "Elapsed time:  " << elapsed.count() << "s\n";
}