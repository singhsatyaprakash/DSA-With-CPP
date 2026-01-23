#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;

class SegmentTree{
private:
    int n;
    vector<long long>tree;
    void buildTree(vector<int>&arr,int start,int end,int node){
        if(start==end){
            tree[node]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        buildTree(arr,start,mid,2*node+1);
        buildTree(arr,mid+1,end,2*node+2);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    long long sumhelper(int l,int r,int start,int end,int node){
        if(r<start || l>end ||l>r){
            return 0;
        }
        if(l<=start && end<=r){
            return tree[node];
        }
        int mid=start+(end-start)/2;
        return sumhelper(l,r,start,mid,2*node+1)+sumhelper(l,r,mid+1,end,2*node+2);
    }
    void updateHelper(int start,int end,int idx,long long val,int node){
        if(start==end){
            tree[node]=val;
            return;
        }
        int mid=start+(end-start)/2;
        if(idx<=mid){
            updateHelper(start,mid,idx,val,2*node+1);
        }
        else{
            updateHelper(mid+1,end,idx,val,2*node+2);
        }
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
public:
    SegmentTree(vector<int>&arr){
        n=arr.size();
        tree.resize(4*n);
        buildTree(arr,0,n-1,0);
    }
    long long sumQuery(int l,int r){
        return sumhelper(l,r,0,n-1,0);
    }
    void updateQuery(int l,int r){
        for(int i=l;i<=r;i++){
            long long mul=sumQuery(l,l);
            long long val=(long long)(i-l+1)*mul;
            updateHelper(0,n-1,i,val,0);
        }
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int q;
    cin>>q;
    vector<vector<int>>queries(q, vector<int>(3));
    for(int i=0;i<q;i++){
        cin>>queries[i][0];
        cin>>queries[i][1];
        cin>>queries[i][2];
    }
    
    long long sum=0;
    SegmentTree st(arr);
    for(auto it:queries){
        int op=it[0];
        int l=it[1];
        int r=it[2];
        if(op==1){//updatequery
            st.updateQuery(l,r);
        }
        else{
            sum=(sum+st.sumQuery(l,r))%MOD;
        }
    }
    cout<<sum<<endl;
    return 0;
}
// we need lazy propogation.... as multiple update...