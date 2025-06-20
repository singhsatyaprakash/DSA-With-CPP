#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool hasDuplicateInWindow(const vector<int>& arr, int k) {
    unordered_set<int> window;
    for(int i = 0; i < arr.size(); i++) {
        if(window.find(arr[i]) != window.end())
            return true;
        window.insert(arr[i]);
        if(window.size() > k)
            window.erase(arr[i - k]);
    }
    return false;
}

int main() {
    int n;
    cout<<"Enter n:";
    cin >> n;
    vector<int> arr(n);
    cout<<"Enter elements:"<<endl;
    for(int i = 0; i < n; i++)
    cin >> arr[i];
    int k;
    cout<<"Enter k:";
    cin >> k;
    if(hasDuplicateInWindow(arr, k)){
        cout << "Duplicate present in window "<<k << endl;
    }
    else{
        cout << "Duplicate not present in window "<<k << endl;
    }
    return 0;
}