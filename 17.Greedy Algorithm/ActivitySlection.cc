#include<iostream>
#include<vector>
using namespace std;
int MaxActivity(vector<int>start,vector<int>end){
    ///sort on basis of end time...
    //A0 select..
    int count=1;
    int currEndTime=end[0];
    for(int i=1;i<start.size();i++){
        if(start[i]>=currEndTime){
            count++;
        }
    }
    return count;
}
int main(){
    vector<int> start={10,9,8};
    vector<int> end={30,40,50};
    cout<<"Maximum actitvity can perform:"<<MaxActivity(start,end)<<endl;
    return 0;
}