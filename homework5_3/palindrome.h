//
// Created by Cassandra Coyle on 3/16/2018.
//

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#ifndef HOMEWORK5_3_PALINDROME_H
#define HOMEWORK5_3_PALINDROME_H

//check if palindrome
int palindrome(std::string inputString) {

    //check string length
    if(inputString.length() < 1 || inputString.length() > 50) {
        return -2;
    }

    std::stack<char> CassieStack;
    std::queue<char> CassieQueue;

    //for each loop to push for every letter
    std::for_each(inputString.begin(),inputString.end(),[&CassieQueue](char &i) {CassieQueue.push(i);});
    std::for_each(inputString.begin(),inputString.end(), [&CassieStack] (char &i) {CassieStack.push(i);});

    //verify they are not empty and check if the top and front are =
    while(!CassieQueue.empty() && !CassieStack.empty()) {
        if (CassieQueue.front() == CassieStack.top()) {
            CassieQueue.pop();
            CassieStack.pop();
        }
        else {
            return -1;

        }
    }
    return 0;
}

#endif //HOMEWORK5_3_PALINDROME_H
