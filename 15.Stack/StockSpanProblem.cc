#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void stockSpanProblem(vector<int> stock, vector<int> span){
    stack<int>s;//storing stack..
    s.push(0);//0 index
    span[0]=1;//no previous high stock..
    for(int i=1;i<stock.size();i++){
        int currPrice=stock[i];
        while(!s.empty() && currPrice>=stock[s.top()]){
            s.pop();
        }
        if(s.empty()){
            span[i]=i+1;
        }
        else{
            int highPrev=s.top();
            span[i]=i-highPrev;
        }
        s.push(i);
    }
    for(int i=0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>stock={100,80,60,70,60,85,100};
    int n=stock.size();
    vector<int>span(n);
    stockSpanProblem(stock,span);
    return 0;
}