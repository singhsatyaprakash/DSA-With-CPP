#include<iostream>
#include<vector>
using namespace std;
int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=arr[0];
    for(int i=1;i<n;i++){
        res=gcd(res,arr[i]);
    }
    cout<<"Result:"<<res<<endl;
    return 0;
}