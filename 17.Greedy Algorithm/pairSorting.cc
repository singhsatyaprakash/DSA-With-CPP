#include<iostream>
#include<vector>
#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}
int main(){
    vector<int>start={1,3,4,5};
    vector<int>end={2,6,5,3};
    vector<pair<int,int>>activity(4,make_pair(0,0));
    activity[0]=make_pair(1,2);
    activity[1]=make_pair(3,6);
    activity[2]=make_pair(4,5);
    activity[3]=make_pair(5,3);
    for(int i=0;i<activity.size();i++){
        cout<<"A"<<i<<":("<<activity[i].first<<","<<activity[i].second<<")"<<endl;
    }
    cout<<"Sorted on basis of end...."<<endl;
    sort(activity.begin(),activity.end(),compare);
    for(int i=0;i<activity.size();i++){
        cout<<"A"<<i<<":("<<activity[i].first<<","<<activity[i].second<<")"<<endl;
    }
    return 0;
}