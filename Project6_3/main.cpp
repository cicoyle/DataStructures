//
// Created by Greg LaKomski on 3/19/18.
//
// My default list of includes for contest coding

#include<sstream>
#include<iostream>
#include<fstream>
#include<cmath>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<limits>
#include<fstream>

using std::cout;
using std::endl;

int main() {

    // input the number of cases
    int cases;
    while (!(std::cin >> cases)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cin.ignore(); // gets rid of /n

    if (cases > 0) {

        std::vector<int> data;
        // for the number of cases
        #pragma omp for
        for (int k = 0; k < cases; k++) {

            std::string line;
            int num;

            getline(std::cin, line);
            std::istringstream iss(line);
            while (iss >> num) {
                data.push_back(num);
            }
            int N = data[0];
            // the rest of data is N speeds of creatures in m per s


// ..................... your code here  ......................
            //sort vector
            sort(data.begin(),data.end());

            //display
            cout << "Case " << k+1 << ": " << data[data.size()-1] << endl;

            //clear vector
            data.clear();

        }


    }
}