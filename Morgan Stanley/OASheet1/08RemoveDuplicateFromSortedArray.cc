#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1)
        return n;

    int idx = 1;
  
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[idx++] = arr[i];
        }
    }
    return idx;
}

int main() {
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter array:"<<endl;
    vector<int> arr(n);
    int newSize = removeDuplicates(arr);
    for (int i = 0; i < newSize; i++) 
        cout << arr[i] << " ";
    return 0;
}