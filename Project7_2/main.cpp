#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

//void display(int flip_arr[50], int flips);

int main()
{
    //initialize to the uva input of btw 1-30 pancakes
    int pancake[30] = {};
    int flip_arr[50] = {};
    char inputString[150];

    //while loop to get the input
    while (gets(inputString)){

        int temp{0};
        int flips{0};
        int counter{0};

        for (int index = 0; inputString[index]; index++){
            if (inputString[index] != ' ')
                temp = temp * 10 + inputString[index] - '0';
            else {
                pancake[counter++] = temp;
                temp = 0;
            }
        }

        pancake[counter++] = temp;
        std::vector<int> vec;

        for (int index = counter - 1; index >= 0; index--)
            vec.push_back(pancake[index]);

        for (int a = 0; a < counter; a++){
            int position{0};

            int max = vec[a];

            for (int b = a + 1; b < counter; b++)
                if (vec[b] > max) {
                    max = vec[b];
                    position = b;
                }
            //reverse vector
            if (position){
                if (position != counter - 1){
                    std::reverse(vec.begin() + position, vec.end());
                    flip_arr[flips++] = position + 1;
                }

                std::reverse(vec.begin() + a, vec.end());
                flip_arr[flips++] = a + 1;
            }
        }
        //display output
        //display(flip_arr, flips);
        for (int i = 0; i < flips; i++)
        printf("%d ", flip_arr[i]);
    puts("0");
    }

    return 0;
}

//void display(int flip_arr[50], int flips) {
//    //output
//    for (int i = 0; i < flips; i++)
//        printf("%d ", flip_arr[i]);
//    puts("0");
//    //fflush(stdout);
//}
//
