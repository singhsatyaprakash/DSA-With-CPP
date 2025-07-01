#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int smallestNonRepresentable(vector<int>& arr) { //O(n log n)
    sort(arr.begin(), arr.end());
    int res = 1;//if array is empty...
    for(int i = 0; i < arr.size(); i++) {
        if (arr[i] > res) {
            break; // If the current element is greater than res, we cannot form res
        }
        res += arr[i]; // Otherwise, we can form all sums up to res + arr[i]
    }
    return res;
}

int main() {
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << "Smallest number that cannot be formed: " << smallestNonRepresentable(arr) << endl;
    return 0;
}
