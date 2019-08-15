//
// Created by Cassandra Coyle on 3/18/2018.
//


#include<iostream>
#include"CircQueue.h"
using std::cout;
using std::endl;

int main() {

    circQueue s;

    s.enqueue(5);
    s.enqueue(6);
    s.enqueue(7);
    s.enqueue(8);

    s.displayQueue();

    int result = s.dequeue();
    cout << " result " << result << endl;
    result = s.dequeue();
    cout << " result " << result << endl;
    result = s.dequeue();
    cout << " result " << result << endl;
    result = s.dequeue();
    cout << " result " << result << endl;
    result = s.dequeue();
    cout << " result " << result << endl;

    s.displayQueue();

    return 0;
}