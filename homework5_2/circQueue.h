//
// Created by Cassandra Coyle on 3/18/2018.
//

#ifndef HOMEWORK5_2_CIRCQUEUE_H
#define HOMEWORK5_2_CIRCQUEUE_H
#include<iostream>
using std::endl;
using std::cout;
#include "linked_list.h"

class circQueue: public linked_list{

private:
    linked_list * a;

public:
    circQueue(){ a = new linked_list; }

    //destructor to delete a and this
    ~circQueue() {
        a->~linked_list();
        delete a, this;
    }

    //display the queue, or if empty cout empty
    void displayQueue() {
        if(a->getHeadPointer() == NULL) {
            std::cout << "Queue is empty." << std::endl;
        } else {
            a->display();
        }
    }

    //enqueue by passing the value to the add node func
    void enqueue(int value) { a->add_node(value); }

    //dequeue by removing from front
    int dequeue(){
        //temp var to set return value
        int temp = 0;

        //if queue is empty
        if(a->getHeadPointer() == NULL)
        {
            //Greg said to cout this in his email
            std::cout<< "tree is empty, returning 0" << std::endl;
            //return 0 as Greg said
            return temp;
        }
        /*else if the head is the tail... ie its the last node*/
        else if(a->getTailPointer() == a->getHeadPointer()) {
            //assign temp to tail data
            temp = a->getTailPointer()->data;

            //delete the head
            delete a->getHeadPointer();

            //set the head and tail ptrs to null
            a->setTailPointer(NULL);
            a->setHeadPointer(NULL);

        }/*dequeue the other nodes that aren't caught in the if & else if*/ else{
            //assign temp to heads data
            temp = a->getHeadPointer()->data;

            //delete the top func
            a->delTop();
        }
        return temp;
    }
};

#endif //HOMEWORK5_2_CIRCQUEUE_H
