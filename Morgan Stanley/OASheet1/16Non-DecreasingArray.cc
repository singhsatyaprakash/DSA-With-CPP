#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        
        for(int i = 1; i < n; i++) {
            if(arr[i-1] > arr[i]) { //decreasing...make increasing by modify..
                count++;
                
                if(count > 1) return false; //one modification allowed...
                
                if(i == 1 || arr[i-2] <= arr[i]) {
                    arr[i-1] = arr[i];  // modify previous
                } else {
                    arr[i] = arr[i-1];  // modify current
                }
            }
        }
        return true;
    }
};