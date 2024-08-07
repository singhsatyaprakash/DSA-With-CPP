#include<iostream>
using namespace std;
void search(int arr[][100],int n,int m,int key,int *r,int *c){
        for(int i=0;i<n;i++){
            //binary search
            int low=0,high=n-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(key<arr[i][mid]){
                    high=mid-1;
                }
                else if(key>arr[i][mid]){
                    low=mid+1;
                }
                else if(key==arr[i][mid]){
                    *r=i;
                    *c=mid;
                    return;
                }
            }
    }

}
int main(){
    int n,m;
    cout<<"Enter matrix size:";
    cin>>n>>m;
    int arr[n][100];
    cout<<"Enter elements of matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
              cin>>arr[i][j];
        }
    }
    int key;
    cout<<"Enter a element to be search:";
    cin>>key;
    int row_idx=-1;
    int col_idx=-1;
    search(arr,n,m,key,&row_idx,&col_idx);
    if(row_idx!=-1&& col_idx!=-1){
    cout<<"Element found at "<<row_idx<<" & "<<col_idx<<endl;
    }
    else{
        cout<<"Element not found...";
    }
    return 0;
}