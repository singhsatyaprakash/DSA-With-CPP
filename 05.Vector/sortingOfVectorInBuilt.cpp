// C++ program to sort a vector in non-decreasing order. 
#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std; 

int main() 
{ 
	vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 2, 2, 0 }; 

	// sort(v.begin(), v.end());//Ascending order-->0 1 2 2 3 5 6 7 8 


	sort(v.begin(), v.end(),greater<int>()); //descending order-->9 8 7 6 5 3 2 2 1 0

	cout << "Sorted:\n"; 
	for (int x : v) 
		cout << x << " "; 

	return 0; 
} 
