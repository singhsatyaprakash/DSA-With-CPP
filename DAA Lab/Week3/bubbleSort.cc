#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>&arr){
    int n=arr.size();
    int comparsion=0,swapcount=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            comparsion++;
            if(arr[j]>arr[j+1]){
                swapcount++;
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<"Comparsion = "<<comparsion<<endl;
    cout<<"Swap = "<<swapcount<<endl;
}
int main(){
    int n,val;
    cout<<"Enter n:";
    cin>>n;
    vector<int>arr;
    cout<<"Enter the elements of array:";
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    bubbleSort(arr);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}