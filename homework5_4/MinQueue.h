//
// Created by Cassandra Coyle on 3/18/2018.
//

#ifndef HOMEWORK5_4_MINQUEUE_H
#define HOMEWORK5_4_MINQUEUE_H

#include <queue>
#include <stack>
#include "CircQueue.h"
#include "Stack.h"
class MinQueue: public circQueue, public stack{
public:
    int queueMin(std::vector<int> inputVector) {
        //vars & pair
        int minNum;
        std::pair<int, int> lePair;

        //Create stack to takes pairs
        std::stack<std::pair<int, int>> CassieStack;
        std::queue<int> CassieQueue;

        int inputVectorSize = inputVector.size();
        //Enqueue value and current min
        for (int i = 0; i < inputVectorSize; i++) {
            //if the stack is empty
            if (CassieStack.empty()) {
                //assign minNum
                minNum = inputVector[i];
                //assign pairs first
                lePair.first = inputVector[i];
                //assign pairs second
                lePair.second = minNum;
                //push to the stack
                CassieStack.push(lePair);
            } else {
                //assign pairs first
                lePair.first = inputVector[i];

                //if pairs first is less than the second
                //figuring out min
                if (lePair.first < CassieStack.top().second)
                    //assign minNum
                    minNum = lePair.first;
                //assign pairs second
                lePair.second = minNum;
                //push to the stack
                CassieStack.push(lePair);

            }
            //push to the queue
            CassieQueue.push(inputVector[i]);
        }
        //return the second
        return CassieStack.top().second;
    }
};
#endif //HOMEWORK5_4_MINQUEUE_H
