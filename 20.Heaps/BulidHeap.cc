#include<iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int>vec;
public:
    void push(int val){
        //1.insert
        vec.push_back(val);
        //2.Fix heap
        int x=vec.size()-1;//inex of child..
        int parI=(x-2)/2;
        while(parI>=0 && vec[x]>vec[parI]){
            swap(vec[parI],vec[x]);
            x=parI;
            parI=(x-2)/2;
        }
    }
    void heapify(int i){
        if(i>=vec.size()){ //  if index is greater than size..
            return;
        }
        int l=2*i+1;
        int r=2*i+2;
        int maxIdx=i;
        if(l<vec.size() && vec[l]>vec[maxIdx]){
            maxIdx=l;
        }
        if(r<vec.size() && vec[r]>vec[maxIdx]){
            maxIdx=r;
        }
        swap(vec[i],vec[maxIdx]);
        //insure that swap is done with child node..
        if(maxIdx != i){
            heapify(maxIdx);
        }
    }
    void pop(){
        swap(vec[0],vec[vec.size()-1]);
        vec.pop_back();
        heapify(0);
    }
    int top(){
        return vec[0];
    }
    bool empty(){
        return vec.size()==0;
    }
};
int main(){
    Heap heap;
    heap.push(12);
    heap.push(120);
    heap.push(10);
    heap.push(100);
    while(!heap.empty()){
        cout<<"Top:"<<heap.top()<<endl;
        heap.pop();
    }
    return 0;
}