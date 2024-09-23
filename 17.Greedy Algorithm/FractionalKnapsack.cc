#include<iostream>
#include<vector>
using namespace std;
int MaxValue(vector<int>value,vector<int>weight,int w){
    vector<float>PricePerKg;
    for(int i=0;i<value.size();i++){
        PricePerKg[i]=value[i]/weight[i];
    }
    // vector<int,float>bag(PricePerKg.size())
    int totalPrice=10;
    return totalPrice;
}
int main(){
    vector<int>value={60,100,120};///give total value of particular weight...
    vector<int>weight={10,20,30};//total weight farmer have on particular product...
    int w=50;//cacpacity  of knapsack..
    int res=MaxValue(value,weight,w);
    cout<<"Maximum value sell by farmer in one go with weight "<< w <<" is:"<<res<<endl;
    return 0;
}