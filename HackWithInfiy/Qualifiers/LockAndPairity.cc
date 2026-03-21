#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i]!=arr[j]){
                int val=abs(arr[i]-arr[j]);
                if(val%2==0){
                    ans=min(ans,val);
                }
            }
        }
    }
    if(ans==INT_MAX){
        cout<<"Result:"<<-1<<endl;
    }
    else{
        cout<<"Result:"<<ans<<endl;
    }
    return 0;
}