//
// Created by Cassandra Coyle on 3/18/2018.
//

#ifndef HOMEWORK5_2_LINKED_LIST_H
#define HOMEWORK5_2_LINKED_LIST_H
#include <iostream>
using std::cout;
using std::endl;
using std::swap;


struct node{
    // this doesnâ€™t have to be an int - think template  we will talk about in class
    int data;
    node *next;
};

class linked_list {
private:
    node *head;
    node *tail;
public:
    // constructor
    linked_list() : head(NULL), tail(NULL) {}

    // destructor
    ~linked_list(){
        node * tmp = new node;
        while(head != tail) {
            tmp = head->next;
            head = NULL;
            delete head;
            head = tmp;
        }
/*************************************************************************/
        //I added in the delete tail.
        //The tail was not deleted,
        //and was not producing the same output
        delete tail;
        tmp = NULL;
        delete tmp;
    }

    // copy constructor - is now implemented
    linked_list(node * rhList){
        //ckeck if the rhList is empty
        //dont return anything since no return type
        if(rhList == NULL) {
            return;
        } else {
            node *otherList = rhList;

            //vars
            node *newList = new node;
            node *tempPtr = newList;
            node *newTail = NULL;

            //go through while loop while otherlist is not null
            while (otherList != NULL) {
                //assign temp ptr data
                tempPtr->data = otherList->data;
                //assign temp ptr to other lists next
                tempPtr = otherList->next;

                //while the other list is not null
                //if the tail is null
                if (newTail == NULL) {
                    //assign the new tail to temp
                    newTail = tempPtr;
                }
                //assign other list to the next one
                otherList = otherList->next;
            }
        }
    }

    // = operator implemented -- is now implemented
    const linked_list & operator = (const linked_list & other){

        //check if this and passed in value are equal
        if(this == &other) {
            //overloaded operators ALWAYS return *this
            return *this;
        }
        //check if the head is not null then you need to destruct it
        else if(this->head != NULL) {
            this->~linked_list();
        }

        //assign leptr to be used in while loop
        node *lePtr = other.head;
        //while loop for while not null
        while(lePtr != NULL) {
            //add the node func passing in leptr data
            this->add_node(lePtr -> data);
            //assign leptr to the next one
            lePtr = lePtr -> next;
        }
        //overloaded operators ALWAYS return *this
        return *this;
    }

    void add_node(int n) {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL){
            head = tmp;
            tail = tmp;
        }else{
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void display(){
        node *tmp;
        tmp = head;
        while (tmp != NULL) {
            std::cout << tmp->data << std::endl;
            tmp = tmp->next;
        }
    }

    // recursive example
    void display(node * start) {
        if(start == NULL){
            cout << "NULL" << endl;
        }else{
            cout << start->data << endl;
            display(start->next);
        }
    }

    void after(node *z, int value) {
        if (z != NULL) {
            node *p = new node;
            p->data = value;
            p->next = z->next;
            z->next = p;
        }

        if(z == tail){
            tail = tail->next;
        }
    }

    void front(int n){
        node *tmp = new node;
        tmp -> data = n;
        tmp -> next = head;
        head = tmp;
    }

    // deletes a node after a specific node before_del
    void del (node *before_del) {
        // if the node before delete is pointing to NULL
        if (before_del->next == NULL) {
            cout << "Trying to delete past end!" << endl;
        } else{
            node *temp;
            temp = before_del->next;
            before_del->next = temp->next;
            delete temp;
        }
    }

    // deletes the top most node - the head node
    void delTop(){
        // if there are no nodes
        if(head == NULL){
            cout << "Empty, nothing to erase" << endl;
        }
        node* temp;
        // if there is only the head node left
        if(head == tail){
            delete head;
        }else{  // more than one node
            temp = head;
            head = head->next;
            delete temp;
        }

    }

    node * getHeadPointer(){
        return head;
    }

    void setHeadPointer(node * newHead){
        head = newHead;
    }

    node * getTailPointer(){
        return tail;
    }

    void setTailPointer(node * newTail){
        tail = newTail;
    }
};
#endif //HOMEWORK5_2_LINKED_LIST_H
