/*Given an array of integers of positive numbers. Find the closest number
with average of those numbers.*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter n:";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter element:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for(auto a : arr) {
        sum += a;
    }

    double avg = (double)sum / n;

    int closest = arr[0];
    double mindiff = abs(arr[0] - avg);

    for(int i = 1; i < n; i++) {
        double currDiff = abs(arr[i] - avg);

        if(currDiff < mindiff) {
            closest = arr[i];
            mindiff = currDiff;
        }
        else if(currDiff == mindiff) {
            closest = min(closest, arr[i]);
        }
    }

    cout << closest;
    return 0;
}

// find closest to k...
class Solution1 {
  public:
    int findClosest(vector<int>& arr, int k) {
        int n = arr.size();
        
        if(k <= arr[0]) return arr[0];
        
        if(k >= arr[n-1]) return arr[n-1];
        
        for(int i = 0; i < n; i++) {
            if(arr[i] >= k) {
                int left = arr[i-1];
                int right = arr[i];
                
                if(abs(k - left) < abs(k - right)) {
                    return left;
                } else {
                    return right;
                }
            }
        }
        
        return -1;
    }
};
//find closest to zero...
class Solution2 {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = nums[0];
        
        for(int i = 0; i < nums.size(); i++) {
            int currDiff = abs(nums[i]);
            int bestDiff = abs(ans);
            
            if(currDiff < bestDiff) {
                ans = nums[i];
            }
            else if(currDiff == bestDiff) {
                ans = max(ans, nums[i]);
            }
        }
        
        return ans;
    }
};