//
//Cassandra Coyle 2/19/18
//
#include "binrep.h"
#include <iostream>
using std::cout;
using std::endl;



int main() {

    cout<< "The number of 1's for N equal to " << "0" << " is " << countBits(0) << endl;
    cout<< "The number of 1's for N equal to " << "15" << " is " << countBits(15) << endl;
    cout<< "The number of 1's for N equal to " << "4" << " is " << countBits(4) << endl;
    cout<< "The number of 1's for N equal to " << "7" << " is " << countBits(7) << endl;

    return 0;
}