#include<iostream>
#include<vector>
using namespace std;
class SegmentTree{
private:
    int n;
    vector<int>tree;
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
    int rangeSum(int qi,int qj,int si,int sj,int node){
        //no overlapping
        if(qj<si || sj<qi){
            return 0;
        }
        //complete overlapping
        if(qi<=si && sj<=qj){
            return tree[node];
        }
        
        //partial overalapping
        int mid=si+(sj-si)/2;
        return rangeSum(qi,qj,si,mid,2*node+1) + rangeSum(qi,qj,mid+1,sj,2*node+2);
    }

    void updateUtil(int idx,int newVal,int start,int end,int node){
        if(start==end){
            tree[node]=newVal;
            return;
        }
        int mid=start+(end-start)/2;
        if(idx>=start && idx<=mid){//left
            updateUtil(idx,newVal,start,mid,2*node+1);
        }
        else{//right
            updateUtil(idx,newVal,mid+1,end,2*node+2);
        }
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
public:
    SegmentTree(vector<int>&arr){
        n=arr.size();
        tree.resize(4*n);
        buildTree(arr,0,n-1,0);//(array,start,end,currNode)
    }
    int rangeQuery(int qi,int qj){
        return rangeSum(qi,qj,0,n-1,0);
    }
    void updateQuery(int idx,int newVal){
        updateUtil(idx,newVal,0,n-1,0);
    }
    void printTree(){
        cout<<endl;
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
    cout<<st.rangeQuery(2,5);// pass range i and j
    st.updateQuery(3,6);//idx and newVal
    st.printTree();
    cout<<st.rangeQuery(2,5);// pass range i and j

}