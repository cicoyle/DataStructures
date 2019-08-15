//
// Created by Cassandra Coyle on 3/18/2018.
//

#ifndef HOMEWORK5_1_COMBINATIONS_H
#define HOMEWORK5_1_COMBINATIONS_H

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
//added in since I had to type in so many std:: before vector
using std::vector;
using std::sort;

//header signatures
vector <vector<int>> combo(vector<int> mainVector, int r, int n);
int highestNumber(vector<int> mainVector);
void eraseRepeats(vector <vector<int>> &mainVector);
void displayVector(vector<vector<int>> &returnedVector);


//function definitions
//deals with all the combination implementation
vector <vector<int>> combo(vector<int> mainVector, int r, int n) {
    //vector
    vector <vector<int>> returnedVector;
    if(r<0 || n<0) {
        cout << "error. negative number.";
        cout << endl;
        return returnedVector;
    } else if(n<1 || n>100){
        cout << "error. n not in input range.";
        cout << endl;
        return returnedVector;
    } else if(r<1 || r>99){
        cout << "error. r not in input range.";
        cout << endl;
        return returnedVector;
    } else if(n<r){
        cout << "error. n<r.";
        cout << endl;
        return returnedVector;
    }

    //for loop to go through the vector
    for(int index = 0; index < mainVector.size(); index++) {
        //if making sure there are no negative values
        if(0 > mainVector[index]) {
            cout << "There are (-) #s in here" << endl;
            return returnedVector;
        }
    }

    //Sort vector
    sort(mainVector.begin(), mainVector.end());

    //for loop running for less than the n in c(n,r)
    for (int i = 0; i < n; i++) {
        //vector temp because you can't just pushback returnedvector.pushback(mainvector[i])
        vector<int> tempVector;
        //push the main vectors values into the temp vector
        tempVector.push_back(mainVector[i]);
        //push the temp vectors values into the returned vector
        returnedVector.push_back(tempVector);
    }
    int t = 0;
    //for loop for all of the sub problems less than r in c(n,r) -1 bc off by 1 otherwise
    //for(int index = 0 ; index < r - 1 ; index++) {
    while(t < (r-1)) {
        //for all the sub problems you need the size to use as the next for loop condition
        int returnedVectorSize = returnedVector.size();

        //for loop to go through the returned vecotr size
        for(int a = 0; a < returnedVectorSize; a++) {
            //vector is initialized to the returned vectors index (a)
            vector<int> tempVector = returnedVector[a];
            int sizeMinusOne = tempVector.size() - 1;
            int mainVectorSize = mainVector.size();

            //for loop running through the main vector
            for(int b =  sizeMinusOne; b < mainVectorSize; b++) {
                //another vector :/ initialized to temp vector
                vector<int> anothaTempVector = tempVector;

                //push the mainvectors values into anotha temp vector
                anothaTempVector.push_back(mainVector[b]);
                //push the anotha temp vector into returned vector
                returnedVector.push_back(anothaTempVector);
                //clear anotha temp vector contents
                anothaTempVector.clear();
            }
        }

        //iterator set at the start of returned vector
        auto iterator = returnedVector.begin();
        //another vector :/
        vector <vector<int>> deletedVector;
        //loop var
        int z = 0;
        auto returnedVectorEnd = returnedVector.end();
        //another for loop :/
        //goes through for loop until iterator reaches the end of returned vector

        while(iterator != returnedVectorEnd) {
            if (returnedVector[z].size() == t + 2) {
                //push the returned vector value to the vector to be deleted
                deletedVector.push_back(returnedVector[z]);
            }
            iterator++;
            z++;
        }


        //assign the deleted vector to the returned vector to delete it
        returnedVector = deletedVector;
        //delete the vector c++11 destroys the elements and leaves the container with a size of 0
        deletedVector.clear();
        t++;
    }//close the big loop

    //get highest
    int highest = highestNumber(mainVector);
    int ARRSIZE = highest + 1;
    //array initialized to 0 using initialization list
    int rateOfOccurence[ARRSIZE] {0};

    auto returnedVectorSize = returnedVector.size();

    //Sort vectors
    int u = 0;
    while(u < returnedVectorSize) {
        sort(returnedVector[u].begin(), returnedVector[u].end());
        u++;
    }

    sort(returnedVector.begin(), returnedVector.end());

    //get rid of dups
    eraseRepeats(returnedVector);

    //figure out how many of the numbers there are
    for(int a = 0; a <= highest; a++)
        for(int b = 0; b < mainVector.size(); b++)
            if(a == mainVector[b])
                rateOfOccurence[a]++;



    int y = 0;
    //Deletes vectors going through arr size
    // for(int a = 0; a<ARRSIZE; a++) {
    while(y<ARRSIZE){
        //last vector :)
        vector <vector<int>> lastTempVector = returnedVector;
        //clear returned vector
        returnedVector.clear();

        auto lastTempVectorSize = lastTempVector.size();
        //for loop going through last temp vector size
        for(int b = 0; b < lastTempVectorSize; b++) {
            int counter = 0;

            for(int c = 0; c < lastTempVector[b].size(); c++) {
                //if they are the same increment the counter
                if (y == lastTempVector[b][c])
                    counter++;
            }
            //check if counter is less than the rate of occurrence of the #
            //if so push it to the return vector
            if (counter <= rateOfOccurence[y])
                returnedVector.push_back(lastTempVector[b]);
        }
        //clear this vector
        lastTempVector.clear();
        y++;
    }

    displayVector(returnedVector);

    return returnedVector;
}

void eraseRepeats(vector <vector<int>> &mainVector) {
    //vars for for loop
    int index;

    auto iterator = mainVector.begin();
    //for loop while iterator is not main vectors end
    for(iterator, index = 0; iterator != mainVector.end();index++, iterator++) {
        while(mainVector[index+1] == mainVector[index])
            mainVector.erase(iterator + 1);
    }
}

int highestNumber(vector<int> mainVector) {
    int currentHigh = 0;
    int mainVectorSize = mainVector.size();
    int index = 0;
    // loop for less than the main vectors size
    while(index < mainVectorSize) {
        if(currentHigh < mainVector[index])
            currentHigh = mainVector[index];
        index++;
    }

    return currentHigh;
}

void displayVector(vector<vector<int>> &returnedVector) {
    int k = 0;
    //display vector contents
    while(k<returnedVector.size()){
        for(int b = 0; b < returnedVector[k].size(); b++) {
        cout << returnedVector[k][b];
        cout << " ";
        }
        cout << endl;
        k++;
    }
}

#endif //HOMEWORK5_1_COMBINATIONS_H






