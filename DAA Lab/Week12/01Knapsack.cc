/* Given a knapsack of maximum capacity w. N items are provided, each having its own value and
 weight. Design an algorithm and implement it using a program to find  the list of the selected
 items such that the final selected content has weight <= w and has maximum value. Here, you
 cannot break an item i.e. either pick the complete item or don't pick it. (0-1 property)*/
#include<iostream>
#include<vector>
using namespace std;
int knapsack(vector<int>&weights,vector<int>&value,int w,int n){
    if(n==0 ||w==0){
        return 0;
    }
    if(weights[n-1]<=w){
        return max(value[n-1]+knapsack(weights,value,w-weights[n-1],n-1),knapsack(weights,value,w,n-1));
    }
    else{
        return knapsack(weights,value,w,n-1);
    }
}
int main(){
    int n;
    cout<<"Enter no. of items:";
    cin>>n;
    vector<int>weights(n);
    vector<int>value(n);
    cout<<"Enter weigths:"<<endl;
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    cout<<"Enter values:"<<endl;
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    int W;
    cout<<"Enter capacity of knapsack:";
    cin>>W;
    cout<<"Maximum value is:"<<knapsack(weights,value,W,n);
    return 0;

}
