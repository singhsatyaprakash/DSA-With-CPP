//Find if any pair in sorted vector has target sum..
//input:[2,7,11,15]
//output:[1,2]-->(indices+1)
#include<iostream>
#include<vector>
using namespace std;
vector<int> pairsum( vector <int> vec,int target){
    int st=0,end=vec.size()-1;
    vector<int>ans;
    while(st<end){
        int currsum=vec[st]+vec[end];
        if(currsum==target){
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }
        else if(currsum>target){
            end--;
        }
        else if(currsum<target){
            st++;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter no. of elements in vector:";
    cin>>n;
    vector<int>vec(n);
    cout<<"Enter elements of vector(sorted order):\n";
    for(int i=0;i<vec.size();i++){
        cin>>vec[i];
    }
    int target;
    cout<<"Enter the target sum:";
    cin>>target;
    vector <int> ans=pairsum(vec,target);
    cout<<ans[0]+1<<","<<ans[1]+1<<endl;
    return 0;
}