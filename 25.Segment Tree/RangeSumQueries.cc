#include<iostream>
#include<vector>
using namespace std;
class SegmentTree{
    int n;
    vector<int>tree;
public:
    SegmentTree(vector<int>&arr){
        n=arr.size();
        tree.resize(4*n);
        buildTree(arr,0,n-1,0);//(array,start,end,currNode)
    }
    void buildTree(vector<int>&arr,int start,int end,int Node){ //O(n)    //2n-1 min nodes
        if(start==end){
            tree[Node]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        buildTree(arr,start,mid,2*Node+1);
        buildTree(arr,mid+1,end,2*Node+2);
        tree[Node]= tree[2*Node+1] + tree[2*Node+2];
    }
    void printTree(){
        for(int i=0;i<tree.size();i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    //Rane in Sum Queries..
    vector<int>arr={1,2,3,4,5,6,7,8};
    SegmentTree st(arr);
    st.printTree();
}