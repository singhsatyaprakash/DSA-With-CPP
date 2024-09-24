#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int MinDiffAbsolute(vector<int>&a,vector<int>&b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int minDiff=0;
    for(int i=0;i<a.size();i++){
        minDiff+=abs(a[i]-b[i]);
    }
    return minDiff;
}
int main(){
    vector<int>A={4,1,8,7};
    vector<int>B={2,3,5,6};
    int res=MinDiffAbsolute(A,B);
    cout<<"Minimum Absoulte Difference of Pairs is: "<<res<<endl;
    return 0;
}