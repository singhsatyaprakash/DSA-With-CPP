/* Given a list of activities with their starting time and finishing time. Your goal is to select
 maximum number of activities that can be performed by a single person such that selected
 activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an
 activity is greater than or equal to the finishing time of the other activity. Assume that a person
 can only work on a single activity at a time.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int MaxActivity(vector<pair<int,int>>&activity){
    //sort on basis of end time... pair{start,end}
    //A0 select...
    sort(activity.begin(), activity.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return a.second < b.second;
    });
    int count=1;
    int currEndTime=activity[0].second;
    for(int i=1;i<activity.size();i++){
        if(activity[i].first>=currEndTime){
            count++;
            currEndTime=activity[i].second;
        }
    }
    return count;
}
int main(){
    int n;
    cout<<"Enter total no. of activity:";
    cin>>n;
    vector<pair<int,int>>activity(n);
    int start,end;
    cout<<"Enter start & end time:"<<endl;
    for(int i=0;i<n;i++){
        cin>>start>>end;
        activity[i]={start,end};
    }
    cout<<"Maximum actitvity can perform:"<<MaxActivity(activity)<<endl;
    return 0;
}