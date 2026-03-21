#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    int h;
    cin>>h;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int i=n-1;
    int currhel=h;
    while(i>=0 && m>0){
        if(arr[i]<=currhel){
            currhel-=arr[i];
            i--;
        }
        else if(currhel){
            m--;
            currhel=h;
        }
    }
    cout<<i+1<<endl;
    return 0;
}