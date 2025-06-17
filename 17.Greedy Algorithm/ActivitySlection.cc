#include<iostream>
#include<vector>
using namespace std;
int MaxActivity(vector<int>start,vector<int>end){
    //sort on basis of end time... pair{end,start}
    //A0 select...
    int count=1;
    int currEndTime=end[0];
    for(int i=1;i<start.size();i++){
        if(start[i]>=currEndTime){
            count++;
            currEndTime=end[i];
        }
    }
    return count;
}
int main(){
    vector<int> start={1,3,0,5,3,5,8,8,2,12};
    vector<int> end={3,5,6,7,9,9,11,12,14,16};//already sorted
    cout<<"Maximum actitvity can perform:"<<MaxActivity(start,end)<<endl;
    return 0;
}