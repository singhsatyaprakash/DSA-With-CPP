#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int>& arr) {
    int n = arr.size();
    int total = 1 << n; // 2^n subsets
    for(int mask = 0; mask < total; mask++) {
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    printSubsets(arr);
    return 0;
}
