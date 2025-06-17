#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool findPairsWithEqualProduct(vector<int>& arr) {
    unordered_map<int, pair<int, int>> productMap; // product , pair of indices
    int n = arr.size();
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            int prod = arr[i] * arr[j];
            if(productMap.find(prod) != productMap.end()) {
                // Check if all indices are distinct
                pair<int, int> prev = productMap[prod];
                if(prev.first != i && prev.first != j && prev.second != i && prev.second != j) {
                    cout << "Pairs found: (" << arr[prev.first] << ", " << arr[prev.second] << ") and ("
                         << arr[i] << ", " << arr[j] << ")" << endl;
                    return true;
                }
            } else {
                productMap[prod] = {i, j};
            }
        }
    }
    cout << "No such pairs found." << endl;
    return false;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    findPairsWithEqualProduct(arr);

    return 0;
}