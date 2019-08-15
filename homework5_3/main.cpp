//
// Created by Cassandra Coyle on 3/16/2018.
//

#include <iostream>
#include "palindrome.h"

int main () {
    int isPalindrome;
    std::string input = "amanaplanacanalpanama";

    isPalindrome = palindrome(input);


    if(isPalindrome == 0) {
        std::cout << "This is a palindrome";
    }
    else if(isPalindrome == -1) {
        std::cout << "This is not a palindrome";
    }
    else if(isPalindrome == -2) {
        std::cout << "Incorrect input";
    }
    return 0;

}

