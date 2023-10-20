/*
Assignment1 - b
Problem Statement : Implement a problem of move all zeroes to end of array.
Given an array of random numbers, Push all the zero’s of a given array to the end of the array. For example, if the given 
arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to
 {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be same.
*/



#include <iostream>
#include <vector>

void moveZerosToEnd(std::vector<int>& arr) {
    int nonZeroCount = 0;

    // Iterate through the array, moving non-zero elements to the front.
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            std::swap(arr[nonZeroCount], arr[i]);
            nonZeroCount++;
        }
    }
}

int main() {
    std::vector<int> arr = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};
    moveZerosToEnd(arr);

    std::cout << "Modified Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}