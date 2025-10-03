#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){//rows change
        for(int j=i;j<n;j++){ //column change
            for(int k=i;k<=j;k++){//printing from row to j length
                cout<<arr[k];
            }
            cout<<", ";
        }
        cout<<endl;
    }
    return 0;
}