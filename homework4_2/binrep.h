//
// Created by Cassandra Coyle on 2/19/2018.
//

#ifndef HOMEWORK4_2_BINREP_H
#define HOMEWORK4_2_BINREP_H

//find out how many 1 bits there are in integer n
int countBits(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    if (n%2 == 1)
        return countBits(n/2) + 1;

    return countBits(n/2);
}
#endif //HOMEWORK4_2_BINREP_H
