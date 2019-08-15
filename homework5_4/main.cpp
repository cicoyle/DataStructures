//
// Created by Cassandra Coyle on 3/18/2018.
//


#include<vector>
#include <iostream>
#include "MinQueue.h"

int main() {
    std::vector<int> inputVector {43, 65, 21, 4, 210};
    MinQueue minQueue;
    int minimum = minQueue.queueMin(inputVector);
    std::cout << "The minimum number is: " << minimum;
    return 0;
}