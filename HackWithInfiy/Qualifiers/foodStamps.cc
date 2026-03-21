#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int>v(n);
    vector<int>d(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    priority_queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        q.push({{v[i],i},0});
    }
    int taste=0;
    while(!q.empty() && m>0){
        int val=q.top().first.first;
        int idx=q.top().first.second;
        int time=q.top().second;
        m--;
        q.pop();
        taste+=val;
        int newval=v[idx]-d[idx]*(time+1);
        q.push({{newval,idx},time+1});
    }
    cout<<"Result:"<<taste<<"\n";
    return 0;
}