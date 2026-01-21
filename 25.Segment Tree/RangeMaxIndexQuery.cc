#include<iostream>
#include<vector>
using namespace std;
class SegmentTree{
    private:
        int n;
        vector<int>tree;
        vector<int>arr;
        void buildTree(vector<int>&arr,int start,int end,int node){
            if(start==end){
                tree[node]=start;
                return;
            }
            int mid=start+(end-start)/2;
            buildTree(arr,start,mid,2*node+1);
            buildTree(arr,mid+1,end,2*node+2);
            int leftidx=tree[2*node+1];
            int rightidx=tree[2*node+2];
            if(arr[leftidx]>arr[rightidx]){
                tree[node]=leftidx;
            }
            else{
                tree[node]=rightidx;
            }
        }
        int maxIndexHelper(int l,int r,int start,int end,int node){
            if(l>end || r<start ||l>r){
                return -1;
            }
            if(l<=start && end<=r){
                return tree[node];
            }
            int mid=start+(end-start)/2;
            int leftidx=maxIndexHelper(l,r,start,mid,2*node+1);
            int rightidx=maxIndexHelper(l,r,mid+1,end,2*node+2);
            if(leftidx==-1){
                return rightidx;
            }
            if(rightidx==-1){
                return leftidx;
            }
            //if both -1 it will return -1..
            ///else...
            if(arr[leftidx]>arr[rightidx]){
                return leftidx;
            }
            else{
                return rightidx;
            }
        }
    public:
        SegmentTree(vector<int>&arr){
            n=arr.size();
            tree.resize(4*n);
            this->arr=arr;
            buildTree(arr,0,n-1,0);
        }
        int maxIndexQuery(int l,int r){
            return maxIndexHelper(l,r,0,n-1,0);
        }
        void printTree(){
            cout<<"\nSegment Tree:\n";
            for(int i=0;i<tree.size();i++){
                cout<<tree[i]<<" ";
            }
        }
};
int main(){
    vector<int>arr={5,3,7,4,1,6};
    SegmentTree st(arr);
    st.printTree();
    cout<<"\n"<<st.maxIndexQuery(1,5);
    cout<<"\n"<<st.maxIndexQuery(3,5);
    return 0;
}
