#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Job{
public:
    int idx;//us jib ka index postion..
    int deadline;
    int profit;
    Job(int idx,int deadline,int profit){
        this->idx=idx;
        this->deadline=deadline;
        this->profit=profit;
    }
};
int MaxProfitCanEarn(vector<pair<int,int>>  pairs){
    int n=pairs.size();
    vector<Job>jobs;
    for(int i=0;i<n;i++){
        jobs.emplace_back(i,pairs[i].first,pairs[i].second);
    }
    sort(jobs.begin(),jobs.end(),[](Job &a,Job &b){//lamda function...
        return a.profit>b.profit;//sorting on basis of profit in desecnding order...
    });
    cout<<"Selecting Job "<<jobs[0].idx<<endl;
    int profit=jobs[0].profit;
    int safeDeadline=2;
    for(int i=1;i<n;i++){
        if(jobs[i].deadline>=safeDeadline){
            cout<<"Selecting Job "<<jobs[i].idx<<endl;
            profit+=jobs[i].profit;
            safeDeadline++;
        }
    }
    return profit;
}
int main(){
    int n=4;//total number of jobs...
    vector<pair<int,int>>pairs(n,make_pair(0,0));
    // make_pair(deadline,profit)...
    pairs[0]=make_pair(4,20);//Job (A/0)
    pairs[1]=make_pair(1,10);//Job (B/1)
    pairs[2]=make_pair(1,40);//Job (C/2)
    pairs[3]=make_pair(1,30);//Job (D/3)
    int res=MaxProfitCanEarn(pairs);
    cout<<"Maxiumum profit can earn with deadline is:"<<res<<endl;
    return 0;
}