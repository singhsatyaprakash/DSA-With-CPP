#include<iostream>
#include<vector>
using namespace std;
class SegmentTree{
private:
    int n;
    vector<int>tree;
    void buildTree(vector<int>&arr,int start,int end,int node){
        if(start==end){
            tree[node]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        buildTree(arr,start,mid,2*node+1);
        buildTree(arr,mid+1,end,2*node+2);
        tree[node]=min(tree[2*node+1],tree[2*node+2]);//minmimumQueries
    }
    int getMinQuery(int qi,int qj,int start,int end,int node){
        if(qj<start || qi>end){//out of range...
            return INT_MAX;
        }
        if(qi>=start && qj<=end){ //totally inside the range...
            return tree[node];
        }
        int mid=start+(end-start)/2;
        return min(getMinQuery(qi,qj,start,mid,2*node+1),getMinQuery(qi,qj,mid+1,end,2*node+2));
    }
    void updateUtils(int idx,int val,int start,int end,int node){
        if(start==end){
            tree[node]=val;
            return;
        }
        int mid=start+(end-start)/2;
        if(idx<=mid){
            updateUtils(idx,val,start,mid,2*node+1);
        }
        else{
            updateUtils(idx,val,mid+1,end,2*node+2);
        }
        tree[node]=min(tree[2*node+1],tree[2*node+2]);
    }
public:
    SegmentTree(vector<int>&arr){
        n=arr.size();
        tree.resize(4*n);
        buildTree(arr,0,n-1,0);
    }
    int minQuery(int l,int r){
        return getMinQuery(l,r,0,n-1,0);
    }

    void update(int idx,int val){
        updateUtils(idx,val,0,n-1,0);
    }
    void printTree(){
        cout<<"Segement Tree:";
        for(int i=0;i<tree.size();i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    vector<int>arr={2,5,6,10,12,17,19,22,23,28};
    SegmentTree st(arr);
    st.printTree();
    cout<<st.minQuery(2,7)<<endl;
    st.update(4,1);//idx,value
    st.printTree();
    cout<<st.minQuery(2,7);
    return 0;
}
