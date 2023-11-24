/*
Implement program to find all distinct subsets of a
given set using Bit Masking Approach.
Statement Given an array of integers arr[], The task is
to find all its subsets. The subset cannot contain 
duplicate elements, so any repeated subset should be
considered only once in the output.
Input: S = {1, 2, 2} Output: {}, {1}, {2}, {1, 2}, {2,
2}, {1, 2,2}
Input: S = {1, 2} Output: {}, {1}, {2}, {1, 2}
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSubsets(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ansList) {
	ansList.push_back(ds);
	for (int i = ind; i < nums.size(); i++) {
		if (i != ind && nums[i] == nums[i - 1])
			continue;

		ds.push_back(nums[i]);
		findSubsets(i + 1, nums, ds, ansList);
		ds.pop_back();
	}
}

vector<vector<int>> AllSubsets(int arr[], int n) {
	vector<int> nums(arr, arr + n);
	vector<int> ds;
	sort(nums.begin(), nums.end());
	vector<vector<int>> ansList;
	findSubsets(0, nums, ds, ansList);
	return ansList;
}

int main() {
	int set[] = { 10, 12, 12 };
	vector<vector<int>> subsets = AllSubsets(set, 3);

	for (auto subset : subsets) {
		cout << "[";
		for (int i = 0; i < subset.size(); i++) {
			cout << subset[i];
			if (i < subset.size() - 1) {
				cout << ", ";
			}
		}
		cout << "], ";
	}

	return 0;
}