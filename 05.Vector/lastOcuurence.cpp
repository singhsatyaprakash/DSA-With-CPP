//Find the last occurence of an elements X in a given array..
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v(6);
    cout<<"Enter elements:";
    for(int i=0;i<6;i++){
        cin>>v[i];
    }
    int x;
    cout<<"Enter x:";
    cin>>x;
    int occurence=-1;
    //travesing fron start...
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            occurence=i;
        }
    }
        cout<<occurence<<endl;
    //travesing fron end...
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]==x){
            occurence=i;
            break;
        }
    }
    cout<<occurence<<endl;
    return 0;
}