#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main(){
    // //Installization...
    // vector<int>vec;
    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(3);
    // vec.push_back(4);
    // for(int i=0;i<vec.size();i++){
    //     cout<<vec[i]<<" ";
    // }
    // cout<<endl;
    // vector<int>v1(5,100);
    // for(int i=0;i<vec.size();i++){
    //     cout<<v1[i]<<" ";
    // }
    // cout<<endl;
    // //copying one vector to another..
    // vector<int>v4={1,2,3,4};
    // //iterator:begin() ,end()
    // vector<int>v5(v4.begin(),v4.end());
    // for(int i=0;i<v5.size();i++){
    //     cout<<v5[i]<<" ";
    // }
    // cout<<endl;
    // //fill(from,to,what)
    // vector<int>v6(5);
    // fill(v6.begin(),v6.end(),11);
    // for(int i=0;i<v6.size();i++){
    //     cout<<v6[i]<<" ";
    // }
    // cout<<endl;
    // //iota(start,end,11)  fill in increasing order 11 12 13 14 15 16
    // fill(v6.begin(),v6.end(),101);
    // for(int i=0;i<v6.size();i++){
    //     cout<<v6[i]<<" ";
    // }
    // cout<<endl;

    // //accesing the element in vector
    // vector<int>x={1,2,3,4,5};
    // cout<<x.at(3)<<endl;//4
    // cout<<x.front()<<" "<<x.back()<<endl;//1
    // //by iterator
    // cout<<*(x.begin()+3)<<endl;//4


    // //travesrsing
    // for(int i=0;i<x.size();i++){
    //     cout<<x[i]<<" ";
    // }
    // cout<<endl;
    // //for each loop
    // for(auto i:x){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto it=x.begin();it!=x.end();it++){//auto=== vector<int>
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    // //rebegin() rend()  //r-->reverse
    // for(auto it=x.rbegin();it!=x.rend();it++){//auto=== vector<int>
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    // if(x.empty()){
    //     cout<<"True"<<endl;
    // }
    // else{
    //     cout<<"False"<<endl;
    // }
    // //inseration and deletion
    // x.push_back(101);
    // for(auto i:x){
    //     cout<<i<<" ";
    // }
    // x.pop_back();//no return of value
    // cout<<endl;
    // for(auto i:x){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // x.insert(x.begin(),69);//(from,value)
    // x.insert(x.begin()+3,54);
    // x.insert(x.end()-4,573647);
    // for(auto i:x){
    //     cout<<i<<" ";
    // }
    // x.insert(x.begin(),5,1);//(iterator,how many time ,value)

    // for(auto i:x){
    //     cout<<i<<" ";
    // }
    // vector<char>x1;
    // vector<char>temp={'a','b','c'};
    // auto first=temp.begin()+1;
    // auto last=temp.begin()+3;
    // x1.insert(x1.begin(),first,last);
    //  for(auto i:x1){
    //     cout<<i<<" ";
    // }

    // vector<int>vec1={1,2,23,43,4,5,55};
    // vector<int>vec2={2,23,43,4,5,55};
    // vec1.swap(vec2);
    // for(int i=0;i<vec1.size();i++){
    //     cout<<vec1[i]<<"    ";
    // }



    //----------------------------crend() cbegin() crbegin() cend()
  vector<int>vec={1,3,4,5,6,67,78,8};
  auto it=vec.begin();
  *it=100;
   for(auto i:x1){
        cout<<i<<" ";
    }

}