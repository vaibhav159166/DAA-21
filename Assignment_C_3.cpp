/*
Implement Check if it is possible to transform one
string to another.
Statement Given two strings s1 and s2 (all letters in uppercase).
Check if it is possible to convert s1 to s2 by performing following
operations.
1. Make some lowercase letters uppercase.
2. Delete all the lowercase letters.
Input: s1 = daBcd s2 = ABC Output: yes
Input: s1 = argaju s2 = RAJ Output: yes
*/


#include <bits/stdc++.h>
using namespace std;


bool check(string s1, string s2)
{

	int n = s1.length();
	int m = s2.length();

	bool dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = false;
		}
	}
	
	dp[0][0] = true;

	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j <= s2.length(); j++) {

			
			if (dp[i][j]) {

				
				if (j < s2.length() && 
					(toupper(s1[i]) == s2[j]))
					dp[i + 1][j + 1] = true;

				
				if (!isupper(s1[i]))
					dp[i + 1][j] = true;
			}
		}
	}

	return (dp[n][m]);
}

int main()
{
	string s1 = "daBcd";
	string s2 = "ABC";

	if (check(s1, s2))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}