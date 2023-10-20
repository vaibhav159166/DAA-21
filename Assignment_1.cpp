/*
Assignment1
Problem Statement: Implement a problem of number of zeroes.
Given an array of 1s and 0s which has all 1s first followed by all 0s? Find the number of 0s. 
Count the number of zeroes in the given array.
*/
// code

#include <iostream>
#include <vector>

int countZeros(std::vector<int>& arr, int left, int right) {
    if (arr[right] == 1) {
        return 0;
    }
    if (arr[left] == 0) {
        return right - left + 1;
    }

    int mid = (left + right) / 2;
    return countZeros(arr, left, mid) + countZeros(arr, mid + 1, right);
}

int main() {
    std::vector<int> arr = {1, 1, 1, 1, 0, 0, 0, 0, 0};
    int count = countZeros(arr, 0, arr.size() - 1);
    std::cout << "Number of zeros: " << count << std::endl;
    return 0;
}