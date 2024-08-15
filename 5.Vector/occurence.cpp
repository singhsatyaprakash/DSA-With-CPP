// Question 1 : Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct. [link]
// Examples :
// Input: nums = [1,2,3,4] Output: false
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
    bool res = false;
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(v[i] == v[j]) {
                res = true;
            }
        }
    }

    if(res) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
