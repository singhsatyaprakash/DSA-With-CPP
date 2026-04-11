#include<bits/stdc++.h>
using namespace std;
int minStops(vector<int>& arr, int K, int X) {
    if (arr[0] == 0 || arr[X] == 0) return -1;

    int pos = 0;
    int stops = 0;

    while (pos < X) {
        int next = -1;
        // greedy jump....
        for (int i = min(X, pos + K); i > pos; i--) {
            if (arr[i] == 1) {
                next = i;
                break;
            }
        }

        if (next == -1) return -1;
        if (next == X) return stops;
        stops++;
        pos = next;
    }

    return stops;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int K, X;
    cin >> K >> X;
    cout << minStops(arr, K, X) << endl;
    return 0;
}