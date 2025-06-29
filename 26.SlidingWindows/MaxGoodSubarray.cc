/*You are given an array A of length N and an integer k.It is given that a subarray from l to r is considered good, if the number of distinct elements in that subarray doesn’t exceed k. Additionally, an empty subarray is also a good subarray and its sum is considered to be zero. Find the maximum sum of a good subarray.*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxGoodSubarraySum(vector<int>& A, int k) {
    int n = A.size();
    unordered_map<int, int> freq;//distinct window size...
    int l = 0;
    long long curr_sum = 0, max_sum = 0;

    for (int r = 0; r < n; ++r) {
        freq[A[r]]++;
        curr_sum += A[r];

        while (freq.size() > k) {//size should be k...remove untill size become k...
            freq[A[l]]--;
            curr_sum -= A[l];
            if (freq[A[l]] == 0) {
                freq.erase(A[l]);
            }
            l++;
        }

        max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cout << maxGoodSubarraySum(A, k) << endl;
    return 0;
}
