#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    int cap;
    cin >> cap;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    long long pref = 0;
    long long minpref = 0, maxpref = 0;

    for(int i=0;i<n;i++){
        pref += arr[i];              // +1 sell, -1 buy
        minpref = min(minpref, pref);
        maxpref = max(maxpref, pref);
    }

    long long low = -minpref;        // minimum X so oil never goes below 0
    long long high = cap - maxpref;  // maximum X so oil never exceeds cap

    if(low <= high){
        cout << low << endl;         // minimum X with 0 disturbance
    } else {
        // disturbance unavoidable, choose closest valid X in [0, cap]
        long long x = low;
        if(x < 0) x = 0;
        if(x > cap) x = cap;
        cout << x << endl;
    }
}
