#include <iostream>
#include <vector>
using namespace std;

void printSubarrays(vector<int>& arr) {
    int n = arr.size();
    for(int start = 0; start < n; start++) {
        for(int end = start; end < n; end++) {
            for(int i = start; i <= end; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    printSubarrays(arr);
    return 0;
}
