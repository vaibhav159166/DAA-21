/*
---------------------------------------------------------------------------------------------------------------------------------------------
Problem Statement : Implement a problem of smallest number with at least n trailing zeroes in factorial.
                    - Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.
---------------------------------------------------------------------------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

// Function to count the number of trailing zeroes in a number
int countTrailingZeroes(int num) {
    int count = 0;
    while (num % 10 == 0) {
        count++;
        num /= 10;
    }
    return count;
}

// Function to find the smallest number whose factorial contains at least n trailing zeroes
int findSmallestNumber(int n) {
    if (n <= 0) return 1;

    int low = 0, high = 5 * n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        int trailingZeroes = countTrailingZeroes(mid);

        if (trailingZeroes < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int smallestNumber = findSmallestNumber(n);
    cout << "The smallest number whose factorial contains at least " << n << " trailing zeroes is: " << smallestNumber << endl;

    return 0;

}



