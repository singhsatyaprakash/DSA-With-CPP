#include<iostream>
using namespace std;
 int main(){
    pair<int,string>p={1.0,"ankit"};
    cout<<p.first<<" "<<p.second<<endl;
    pair r(1,'q');
    cout<<r.first<<" "<<r.second<<endl;
    pair s(r);
    cout<<s.first<<" "<<s.second<<endl;
    pair<int,int>q;
    q=make_pair(7,8);
    cout<<q.first<<" "<<q.second<<endl;
    pair<int,pair<int,int>>p1={1,{3,4}};
    cout<<p1.first<<" "<<p1.second.second<<" "<<p1.second.first<<endl;
    //initalize with zero
    pair<int,int>a;
    // pair<int,string>a;
    cout<<a.first<<" "<<a.second<<endl;

    //swaping data type must be same
    pair<int,int>x={1,2};
    pair<int,int>z={3,4};
    x.swap(z);
    cout<<x.first<<" "<<x.second<<endl;

    //array with pair
    pair<int,int>arr[]={{1,2},{3,4}};
    cout<<arr[1].first<<endl;
    return 0;
}