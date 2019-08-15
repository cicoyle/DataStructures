/* C Program to check for majority element in a sorted array */
# include <stdio.h>
#include <iostream>

using std::cout;


bool isMajority(int arr[], int number_of_elements, int majority_number)
{

    /* get last index according to n (even or odd) */
    int last_index = number_of_elements%2? (number_of_elements/2+1): (number_of_elements/2);

    /* search for first occurrence of x in arr[]*/
    for (int i = 0; i < last_index; i++)
        if (arr[i] == majority_number && arr[i+number_of_elements/2] == majority_number)
            return 1;


    return 0;
}

/* Driver program to check above function */
int main()
{
    int arr[] ={3, 3, 4, 2, 4, 4, 2, 4, 4};
    int number_of_elements = sizeof(arr)/sizeof(arr[0]);
    int majority_number = 4;

    if (isMajority(arr, number_of_elements, majority_number)) {
        cout << majority_number  << " appears more than ";
        cout << number_of_elements / 2  << " times in arr[] ";

    }
    else
        printf("%d does not appear more than %d times in arr[]", majority_number, number_of_elements/2);

    return 0;
}