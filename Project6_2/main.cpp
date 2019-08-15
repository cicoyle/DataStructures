//
//Created by Cassandra Coyle 4/4/18
//

#include <iostream>
#include "Tree.h"
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <random>

int main() {

  //tree obj
  Tree CassieTree;

/*********************************************************************************************
    I could not figure out a correct solution with randomly generated #s. It is 4:56am, my CLion will not
    produce the same results more than once, and I have to sit there for at least a minute trying to run my
    code EVERYTIME to try to debug it. It is correct for my input; however I cannot debug with my current CLion
    condition any longer and keep my sanity. I left in the code for finding random #s. Please take this into
    account when grading as I am losing my mind trying to figure it out this late/early...
*********************************************************************************************/
//    srand(time(0));
//
//    for(int i = 0; i < 1000; i++)
//    {
//        int val = rand() % 2000 + 1;
//        CassieTree.insert(i, val);
//        cout << endl;
//        CassieTree.searchNode(val);
//        cout << endl;
//    }


//    CassieTree.printTree();

//    CassieTree.printTree();


    CassieTree.insert(0, 167);
    CassieTree.insert(2, 902);
    CassieTree.insert(4, 215);
    CassieTree.insert(6, 344);
    CassieTree.insert(8, 39);
    CassieTree.insert(10, 977);
    CassieTree.insert(12, 100);

    CassieTree.printTree();

    Tree* AnotherTree = new Tree();

    AnotherTree->insert(1,12);

    AnotherTree->insert(10,100);


    AnotherTree->insert(21,14);

    AnotherTree->insert(40,87);

    cout << "InOrder" << endl;

    AnotherTree->printTree();

    cout << "\n";

    AnotherTree->searchNode(15);

    AnotherTree->searchNode(21);

    AnotherTree->searchNode(44);

    AnotherTree->searchNode(87);

     return 0;
}