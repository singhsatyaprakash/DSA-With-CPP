#include<iostream>
#include<vector>
using namespace std;
class SegementTree{
    private:
        int n;
        vector<int>tree;
        vector<int>lazy;
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
        
        void push(int node,int start,int end){
            if(lazy[node]==0) return;//means no pending update...
            tree[node] += (end-start+1) * lazy[node]; //update at that node..
            if(start!=end){//propgating to their child nodes...when we will travese to child on upcoming quereies we will update...
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }
            lazy[node]=0;
        }
       
        int sumUtils(int l,int r,int start,int end,int node){
            if(l>end || r<start || l>r) return 0;

            push(node,start,end);//when we reach to the node we will check for any update pending due to lazy??...

            if(l<=start && end<=r) return tree[node];

            int mid=start+(end-start)/2;
            return sumUtils(l,r,start,mid,2*node+1) + sumUtils(l,r,mid+1,end,2*node+2);
        }
        void updateHelper(int l,int r,int val,int start,int end,int node){
            if(l>end || r<start || l>r) return;

            push(node,start,end);

            if(l<=start && end<=r){
                lazy[node] += val;
                push(node,start,end);
                return;
            }

            int mid=start+(end-start)/2;
            updateHelper(l,r,val,start,mid,2*node+1);
            updateHelper(l,r,val,mid+1,end,2*node+2);
            tree[node]=tree[2*node+1]+tree[2*node+2];
        }
    public:
        SegementTree(vector<int>&arr){
            n=arr.size();
            tree.resize(4*n);
            lazy.resize(4*n,0);
            buildTree(arr,0,n-1,0);
        }
        int getSumQuery(int l,int r){
            return sumUtils(l,r,0,n-1,0);
        }
        void updateQuery(int l,int r,int val){
            updateHelper(l,r,val,0,n-1,0);
        }
        void printTree(){
            cout<<"Segement Tree:\n";
            for(int i=0;i<tree.size();i++){
                cout<<tree[i]<<" ";
            }
            cout<<endl;
        }
        void printLazy(){
            cout<<"Lazy Tree:\n";
            for(int i=0;i<lazy.size();i++){
                cout<<lazy[i]<<" ";
            }
            cout<<endl;
        }

};
int main(){
    vector<int>arr={3,4,2,5,3,6,3,4};
    SegementTree st(arr);
    st.printTree();
    cout << "sum(0,n-1)=" << st.getSumQuery(0,(int)arr.size()-1) << "\n";
    st.updateQuery(2,5,2);
    cout << "sum(0,n-1) after update=" << st.getSumQuery(0,(int)arr.size()-1) << "\n";
    st.printTree();
    st.printLazy();
    st.updateQuery(3,7,1);
    cout << "sum(0,n-1) after update=" << st.getSumQuery(0,(int)arr.size()-1) << "\n";
    st.printTree();
    st.printLazy();
    st.updateQuery(4,5,1);
    cout << "sum(0,n-1) after update=" << st.getSumQuery(0,(int)arr.size()-1) << "\n";
    st.printTree();
    st.printLazy();
}