#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter stocks:"<<endl;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int min_price=INT_MAX;
    int max_profit=0;
    for(int i=0;i<n;i++){
        min_price=min(min_price,arr[i]);
        max_profit=max(max_profit,arr[i]-min_price);
    }
    cout<<"Max Profit:"<<max_profit<<endl;
    return 0;
}