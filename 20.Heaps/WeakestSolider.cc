#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Row{
public:
    int idx;
    int count;
    Row(int idx,int count){
        this->idx=idx;
        this->count=count;
    }
    bool operator <(const Row&obj)const{
        if(this->count==obj.count){
            return this->idx >obj.idx;//min heap
        }
        return this->count >obj.count;
    }
};
void weakestSoldier(vector<vector<int>>matrix,int k){
    //we need to store count of solider in row and their idx position.. NEED CLASS

    //to build heap we need data in vector form..
    vector<Row>rows;
    for(int i=0;i<matrix.size();i++){
        int count=0;
        for(int j=0;j<matrix[i].size()&& matrix[i][j]==1 ;j++){//as all soliders are in front of row..
            count++;
        }
        rows.push_back(Row(i,count));
    }

    priority_queue<Row>pq(rows.begin(),rows.end());

    for(int i=0;i<k;i++){
        cout<<"WEAK: group"<<pq.top().idx+1<<endl;
        pq.pop();
    }
}
int main(){
    vector<vector<int>>matrix{{1,0,0,0},{1,1,1,1},{1,1,0,0},{1,0,0,0}};
    int k=2;
    weakestSoldier(matrix,k);
    return 0;
}