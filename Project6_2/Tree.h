//
// Created by Greg LaKomski on 3/20/18.
//

#ifndef HOMEWORK6_TREE_H
#define HOMEWORK6_TREE_H

#include<utility>
#include<iostream>
using std::cout;
using std::endl;

// Note the nested classes - look this up!
// I could have added parent pointers to make deletion more efficient
// The node class will have both the key and an associated value you can carry with. Should remind you of a MAP or SET.
class Tree {
private:
    //private member vars
    int totalComparisons = 0;
    int maximumComparisons;
    int minimumComparisons;

    class Node {
    private:
        Node * left;
        Node * right;
        int key;
        int value;

    public:
        //provided
        Node( int key, int value ) {
            this->key = key;
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
        //I thought you didn't like friend class'?
        friend class Tree;
    };

    // this is part of the Tree class
    Node * head;

    //getters and setters for the maximum comparisons
    int getMaximumComparisons(){
        return maximumComparisons;
    }
    //getters and setters for the maximum comparisons
    void setMaximumComparisons(int max){
        maximumComparisons = max;
    }

    //getters and setters for the minimum comparisons
    int getMinimumComparisons(){
        return minimumComparisons;
    }
    //getters and setters for the minimum comparisons
    void setMinimumComparisons(int min){
        minimumComparisons = min;
    }

    //getters and setters for the total # of comparisons
    int getTotalComparisons(){
        return totalComparisons;
    }
    //getters and setters for the total # of comparisons
    void setTotalComparisons(int compares){
        totalComparisons = compares + totalComparisons;
    }

    //done
    //Helper function for printTree
    void printInOrder(Node * node) {
        //if node is null return nothing
        if (node == NULL)
            return;
        else {
            //go left if not null
            if(node->left != NULL){
                printInOrder(node->left);}

            //print the value to check
            std:: cout << "value: " << node->value << std:: endl;

            //go right if not null
            if(node->right != NULL){
                printInOrder(node->right);}
        }
    }

    //done
    // insert Binary search tree insertion helper
    Node * BSTInsert(Node* y, Node * head) {
        //check if head is null
        if (head == NULL) {head = new Node(y->key, y->value);}
            /*code added= to check left/right*/else{
            //if the value is less than the head value insert left in tree
            if(head->value > y->value) {head->left = BSTInsert(y,head->left);}
                //if the value is greater than the head value insert right in tree
            else if(head->value < y->value){head->right = BSTInsert(y,head->right);}
        }

        return head;
    }

    //done
    //This is a height helper function for function height
    int heightHelper(Node * node){
        //vars
        int leftHeight = 0;
        int rightHeight = 0;

        //ifs to see if left/right is not null
        //if not null then go to next node (either left or right)
        if(node->left != NULL){leftHeight = heightHelper(node->left);}
        if (node->right != NULL){rightHeight = heightHelper(node->right);}

        //increase height by 1
        rightHeight = (rightHeight + 1);
        leftHeight = (leftHeight + 1);

        //check which height is bigger
        if(leftHeight > rightHeight){return leftHeight;}
        else {return rightHeight;}
    }

    //done
    // this is the helper function for search function
    std::pair<bool,int> searchHelper(int key){
        //vars
        bool flag = false;
        Node *tmpNode = head;

        //check if empty
        if (tmpNode == NULL){
            flag = false;}

        int counter = 0;

        //while tmpnode is not null meaning there are nodes
        while (tmpNode != NULL){
            //if the head nodes value is the data we are looking for flag is true
            if (key == tmpNode->value){
                flag = true;
                //NEEDS BREAK
                break;
            }/*go right if data is bigger*/else if (tmpNode->value < key){
                counter++;
                tmpNode = tmpNode->right;
            }/*go left if data is smaller*/else if (tmpNode->value > key){
                counter++;
                tmpNode = tmpNode->left;
            }
        }
        return std:: pair <bool, int> (flag, counter);
    }


public:
    //provided
    Tree() { head = NULL; }
    //provided
    Node * createNode(int key, int value){
        Node * temp = new Node(key,value);
        return temp;
    }

    //provided
    //Prints the keys for the tree in inorder mode
    // Helper function in private section
    void printTree(){
        printInOrder(this->head);
    }
    //provided
    //Inserts a node into the tree
    // Helper function in private section
    void insert(const int key, const int value){
        Node * temp = new Node(key,value);
        this->head = BSTInsert(temp,this->head);
    }

    //done
    //Deletes a node with a specific key, returns TRUE or FALSE and the # of compares done. - a pair.
    // Helper function in private section
    std::pair<bool,int> searchNode(int key){
        //pair
        std::pair<bool,int> returned = searchHelper(key);
        //display to verify
        std:: cout << "Searching for value: " << key << std:: endl;
        //var
        int comp = (returned.second + 1);
        //display comparisons
        std:: cout << "# of comparisons: " << comp << std:: endl;
        std::cout << "minimum compares made: " << getMinimumComparisons() << std::endl;
        std::cout << "maximum compares made: " << getMaximumComparisons() << std::endl;

        //set the # of total comparisons
        setTotalComparisons(comp);
        std::cout << "Total # of comparisons: " << getTotalComparisons() <<std::endl;

        //calculate the average be sure to CAST INTS
        float avg = (float)getTotalComparisons()/(float)comp;
        std::cout << "Average comparisons made: " << avg << std::endl;

        comp+1;

        //set min/max comps
        if(comp < getMinimumComparisons()) {setMinimumComparisons(comp);}
        if(comp > getMaximumComparisons()) {setMaximumComparisons(comp);}

        //check if found/not found
        if(returned.first == true) {std::cout << "Value present" << endl;}
        if(returned.first == false){std::cout << "Value NOT present" << endl;}
        return returned;
    }

    //height function
    int height(){
        //vars initialized to something they would never be
        int treeHeight = -1;
        int leftTreeHeight = -1;

        //check if head is null ie... empty
        if(head == NULL) {return treeHeight;}
        else{ /*add 1 for the root*/
            treeHeight = (1 + std::max(heightHelper(head->left), heightHelper(head->right)));
        }

        //assign vars
        leftTreeHeight = (heightHelper(head->left));
        int rightTreeHeight = heightHelper(head->right);
        //display vars
        std::cout << "Left subtree height is: " << leftTreeHeight << std::endl;
        std::cout << "Right subtree height is: " << rightTreeHeight << std::endl;
        return treeHeight;
    }

    // add create a node with key, value and both pointers

    // add insert,search (should return TRUE and
    // number of comparisons to find it or FALSE and number of comparisons) and height methods for the tree class
    // sounds like search should return a pair, yes?

};

#endif //HOMEWORK6_TREE_H