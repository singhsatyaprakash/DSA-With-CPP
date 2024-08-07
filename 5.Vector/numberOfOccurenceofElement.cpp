//cout the number of occurence of a particular element x..
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector <int> v(n);
    cout<<"Enter elements  of vector:"<<endl;
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    //searching elements how many time occurences
    int x;
    cout<<"Enter elements to be search:";
    cin>>x;
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            count++;
        }
    }
    cout<<"Total "<<count<<" occurence of element "<<x<<endl;
    return 0;
} 