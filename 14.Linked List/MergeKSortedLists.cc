#include <bits/stdc++.h>
using namespace std;

// Merge a and b into c
void mergeArrays(vector<int>& a, vector<int>& b, 
                                 vector<int>& c) {
    int i = 0, j = 0, k = 0;
    int n1 = a.size();
    int n2 = b.size();
    c.resize(n1 + n2);

    // Traverse both arrays
    while (i < n1 && j < n2) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    // Store remaining elements of a
    while (i < n1)
        c[k++] = a[i++];

    // Store remaining elements of b
    while (j < n2)
        c[k++] = b[j++];
}

// This function takes a vector of vectors as an argument and
// All arrays are assumed to be sorted. It merges them
// together and returns the final sorted output.
void mergeKArrays(vector<vector<int>>& arr, int lo, int hi,
                                       vector<int>& res) {
  
    // If one array is in range
    if (lo == hi) {
        res = arr[lo];
        return;
    }		

    // If only two arrays are left, merge them
    if (hi - lo == 1) {
        mergeArrays(arr[lo], arr[hi], res);
        return;
    }

    // Calculate mid point
    int mid = (lo + hi) / 2;

    // Divide the array into halves
     // Output arrays
    vector<int> out1, out2;
    mergeKArrays(arr, lo, mid, out1);
    mergeKArrays(arr, mid + 1, hi, out2);

    // Merge the output arrays
    mergeArrays(out1, out2, res);
}

// Driver's code
int main() {
    vector<vector<int>> arr = { { 1,4,5 },
                                { 1,3,4 },
                                { 2,6   } };

    vector<int> res;
    mergeKArrays(arr, 0, arr.size() - 1, res);
  
    for (int val : res)
        cout << val << " ";
    cout << endl;

    return 0;
}