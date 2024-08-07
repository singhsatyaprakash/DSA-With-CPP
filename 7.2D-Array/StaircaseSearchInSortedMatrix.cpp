//Brute force O(N^2)
#include<iostream>
using namespace std;
void search(int arr[][100],int n,int m,int key,int *r,int *c){
//Staircase...O(n+m)
    int i=0,j=n-1;
    while(i<n&&j>=0){
        if(arr[i][j]==key){
            *r=i;
            *c=j;
            return;
        }
        else if(arr[i][j]>key){
            //left
            j--;
        }
        else{//arr[i][j]>key...
            //down
            i++;
        }
    }
    return;//not found...

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
    cout<<"Element found at "<<row_idx<<" & "<<col_idx<<endl;
    return 0;
}