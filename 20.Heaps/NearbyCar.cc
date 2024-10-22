#include<iostream>
#include<vector>
#include<queue>
#include<string>
//#include <bits/stdc++.h>
using namespace std;
class Car{
public:
    //we have store idex with disatsquare...
    int idx;
    int distSq;
    Car(int idx,int distSq){
        this->idx=idx;
        this->distSq=distSq;
    }
    bool operator <(const Car&obj) const{ // const shoulde be their for pq..
        return this->distSq >obj.distSq;
    }
};
void NearByCar(vector<pair<int,int>>pos,int k){
    //makelist of cars..
    vector<Car>cars;
    for(int i=0;i<pos.size();i++){
        int distSq= (pos[i].first * pos[i].first) +(pos[i].second * pos[i].second);
        cars.push_back(Car(i,distSq));
    }
    //now create heap with the  cars..
    priority_queue<Car>pq(cars.begin(),cars.end());//O(n)
    /*//O(n*logn)
    priority_queue<Car>pq;
    for(int i=0;i<cars.size();i++){
        pq.push(cars[i]);
    }
    */
    //we need min heap to here we have object so we have to overload in class..
    for(int i=0;i<k;i++){
        cout<<"Car:C"<<pq.top().idx+1<<endl;
        pq.pop();
    }
}
int main(){
    vector<pair<int,int>>pos; //coordinate(x,y)
    pos.push_back(make_pair(3,3));//c1
    pos.push_back(make_pair(5,-1));//c2
    pos.push_back(make_pair(-2,4));//c3
    pos.push_back(make_pair(1,1));//c4
    int k=2;
    NearByCar(pos,k);
    return 0;
}