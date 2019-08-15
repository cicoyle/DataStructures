

#include <vector>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string>
#include <set>
#include <cstdio>
#include <iterator>
#include<set>


using std::cout;
using std::endl;

//used vector not struct

int main() {

    //10-18 range for hours = 8 hours
    //total mins because 8 hours and 60 mins in an hour
    int totalMins{8 * 60};

    //off by 1, so added +1
    //actually off by 2, so had to add +2
    std::vector<bool> timeVec(totalMins + 1 + 1);

    //vars and initialize them
    int N;
    std::string trash;
    int day{0};

    //initialize to false first
    timeVec[totalMins + 1] = false;

    while(std::cin >> N) {
        day++;
        //... filled in
        //for loop to initialize the vector to true when it is less than the totalmins
        for (int i = 0; i <= totalMins; i++)
            timeVec[i] = true;

        //initialize vars
        int nap{0};
        int startNap{0};

        //gregs provided template
        while(N--) {

            int startHr, startMin, endHr, endMin;
            int startTime, endTime;
            char startSeparator, endSeparator;

            std::cin >> startHr >> startSeparator >> startMin >> endHr >> endSeparator >> endMin;
            getline(std::cin, trash);

            startTime = (startHr - 10) * 60 + startMin;
            endTime = (endHr - 10) * 60 + endMin;

            //code to store the appts in vector
            for (int i = startTime; i < endTime; i++)
                timeVec[i] = false;
        }
        //... filled in
        //dealt with the end cases
        //verify with all the ifs during the for loop duration
        //basically like iterating through the total mins
        for(int index = 0; index <= totalMins; index++) {
            //temp var
            int tempIndex;
            int nextIndex = index+1;
            //if true, assign temp to the next index kindof like iterating
            if (timeVec[index] == true) {
                tempIndex = nextIndex;

                //when the initial index is true and while the temporary index is true
                while(timeVec[tempIndex] == true) tempIndex++;
                //if the temporary is the total mins +1 then - moving back the tempindex into range
                if(tempIndex == totalMins + 1) tempIndex--;
                //check if the nap is less then the temporary - index
                //assign the new nap to the best nap within the indexes
                int range = tempIndex - index;
                //assign the new best start time to the
                if(nap < range) {
                    startNap = index;
                    nap = range;
                }

                //assign the index to temp
                index = tempIndex;
            }
        }
        //OK - got your best nap time for a given day - sorry about the wrapping :(
        //best nap time for a given day--tweaked Gregs
        if(nap >= 60)
            printf("Day #%d: the longest nap starts at %d:%02d and will last for %d hours and %d minutes.\n", day,
                   startNap / 60 + 10, startNap % 60, nap / 60, nap % 60);
        else
            printf("Day #%d: the longest nap starts at %d:%02d and will last for %d minutes.\n", day,
                   startNap / 60 + 10, startNap % 60, nap);
    }
    return 0;
}


