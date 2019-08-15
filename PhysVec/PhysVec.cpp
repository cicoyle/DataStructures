//
// Created by Cassandra Coyle on 1/25/2018.
//
//This file provides the implementation of the PhysVec.h header file
#include <iostream>

#include <vector>
#include "PhysVec.h"
using std::cout;
using std::endl;

//Default constructor for a vector
PhysVec::PhysVec(){

}

//This function takes in a vector as input and creates a PhysVec vector
//for the output
PhysVec::PhysVec(const std::vector<int> &input_vec) {
    (*this).a_vec_ = input_vec;
}

//This function is a copy constructor to generate a NEW instance
PhysVec::PhysVec(const PhysVec &rhs) {
    a_vec_ = rhs.a_vec_;
}

//This function will iterate through the vectors to copy them
//element by element and will return an object reference
//aka an instance pointer
PhysVec &PhysVec::operator= (const PhysVec & rhs){
    if (this->a_vec_.size() != rhs.a_vec_.size()){
        throw std::invalid_argument("vectors are not the same length");
    }

//cout << "this: " << this << endl;
//  cout << "&rhs: " << &rhs << endl;
    //Check if they are already equal
    if(this == &rhs)
        return *this;

    //Create the iterators
    //First one is const because rhs is const
    std::vector<int>::const_iterator iterator_one;
    std::vector<int>::iterator iterator_two;

//STUFF FOR MAKING SURE THEY ARE THE SAME SIZE



    for(iterator_one = rhs.a_vec_.begin(), iterator_two = this->a_vec_.begin();
        iterator_one != rhs.a_vec_.end(), iterator_two != this->a_vec_.end();
        iterator_one++, iterator_two++)
    {
        *iterator_two = *iterator_one;
    }

//  cout << "Done with operator= function" << endl;

    return *this;
}


//This function will add the same elements in 2 vectors and
//place the sum into a 3rd vector
PhysVec PhysVec::operator+ (const PhysVec & rhs) const{
    //Throw a runtime error if the vectors are of different sizes
    if(this->a_vec_.size() != rhs.a_vec_.size())
        throw std::runtime_error("The vectors are of different sizes; thus,"
                                         "they can NOT be added together.");

//  //If vectors are same size, create a 3rd vector
    //std::vector<int> result_vector;
    PhysVec addition_result_vector(rhs);
    //result_vector.reserve(rhs.a_vec_.size());
    //cout << "result_vector.Size() == " << addition_result_vector.a_vec_.size() << endl;
    //cout << "size of result vector: " << rhs.a_vec_.size() << endl;
//
//  cout << "addr result_vector" << &addition_result_vector << endl;
//  cout << "addr rhs_vector" << &rhs << endl;

    std::vector<int>::const_iterator iterator_one = this->a_vec_.begin();  //lhs
    std::vector<int>::const_iterator iterator_two = rhs.a_vec_.begin();
    std::vector<int>::iterator iterator_three = addition_result_vector.a_vec_.begin();

    while(iterator_two != rhs.a_vec_.end())
    {
        cout << "vector contents: " << *iterator_one << " + " << *iterator_two;//"lhs content (iterator1) " << *iterator1 << endl;
        (*iterator_three) = (*iterator_one) + (*iterator_two);
        cout << " = " << *iterator_three << endl;//"rhs content (iterator2) " << *iterator2 << endl;
//    cout << "i1 addr:" << iterator_one.base() << endl;
//    cout << "i2 addr:" << iterator_two.base() << endl;
//    cout << "i3 addr:" << iterator_three.base() << endl;
        iterator_one++;
        iterator_two++;
        iterator_three++;
    }

    return addition_result_vector;
}

//This function will be used to figure out the dot product
//using 2 iterators
int PhysVec::calculateDotProduct(const PhysVec & rhs) const{
    int dot_product = 0;

    //if (this->a_vec_.size() != rhs.a_vec_.size()){
 //       throw std::invalid_argument("vectors are not the same length and you are trying to take the dot product");
   // }

    std::vector<int>::const_iterator iterator_one = this->a_vec_.begin();
    std::vector<int>::const_iterator iterator_two = rhs.a_vec_.begin();

    while((iterator_one != a_vec_.end()) && (iterator_two != rhs.a_vec_.end())){
        dot_product += ((*iterator_one) * (*iterator_two));
        iterator_one++;
        iterator_two++;
    }
    return dot_product;
}

//This function is a setter function. It will create a non constant
//PhysVec.


//This function is a getter function. It will turn a PhysVec
//vector into a normal vector
std::vector<int> &PhysVec::get_a_vec_() {
    return this->a_vec_;
}

//This function will print out a vector. It must iterate
//through each element to print out each part of the vector
void PhysVec::printVecs() const {
    cout << "Vector contents: ";

    std::vector<int>::const_iterator vector_iterator;

    for (vector_iterator = this->a_vec_.begin(); vector_iterator != a_vec_.end(); vector_iterator++)
        cout << *vector_iterator << ' ';

    cout << endl;
}
void PhysVec::setPhysVec(const std::vector<int> &input_vec) {
    (*this).a_vec_ = input_vec;
}
