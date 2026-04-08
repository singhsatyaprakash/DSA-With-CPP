#include<bits/stdc++.h>
using namespace std;
class SegmentTree{
    int n;
    vector<int>tree;
    void buildTree(int node,int start,int end,vector<int>&arr){
        if(start==end){
            tree[node]=arr[start];
            return;
        }
        int mid=(start+end)/2;
        buildTree(2*node+1,start,mid,arr);
        buildTree(2*node+2,mid+1,end,arr);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }
    int maxhelper(int node ,int start,int end,int l,int r){
        if(r<start || end<l){
            return 0;//out of range
        }
        if(l<=start && end<=r){
            return tree[node];
        }
        int mid=(start+end)/2;
        int leftMax=maxhelper(2*node+1,start,mid,l,r);
        int rightMax=maxhelper(2*node+2,mid+1,end,l,r);
        return max(leftMax,rightMax);
    }
public:
    SegmentTree(vector<int>&arr){
        n=arr.size();
        tree.resize(4*n, 0);
        buildTree(0,0,n-1,arr);//nodd,start,end,array...
    }
    int getMax(int l,int r){
        return maxhelper(0,0,n-1,l,r);
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>bonus(n);
    for(int i=0;i<n;i++){
        cin>>bonus[i];
    }
    SegmentTree st(bonus);
    int ans=0;
    for(int i=0;i<n;i++){
        //search for the rightmost multiple..
        int r=-1;
        for(int j=i+1;j<n;j++){
            if(arr[j]%arr[i]==0){
                r=j;
                break;
            }
        }
        if(r!=-1){
            int maxi=st.getMax(i,r);
            ans+=maxi;
        }
    }
    cout<<ans<<endl;
    return 0;
}