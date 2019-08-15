//
// Created by Cassandra Coyle on 3/18/2018.
//

#include <iostream>
#include "combinations.h"

int main() {
    std::vector<int> data{1,2,3,4,5};
    auto results = combo(data,3,5);

    std::cout << "Second" << endl;
    // Testing smallest valid N and R
    results = combo(data,1,1);

    std::cout <<endl << "Third" << endl;
    // Testing largest Valid N and R
    results = combo(data, 99,100);
    std::cout <<endl;

    // Testing bad input - neg numbers
    std::cout << "neg. r";
    results = combo(data, -1,5);
    std::cout << "neg. n";
    results = combo(data, 1,-5);

    std::cout << "n<r";
    results = combo(data, 5, 3);

    return 0;
}