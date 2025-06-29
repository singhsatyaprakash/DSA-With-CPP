#include<iostream>
#include<vector>
using namespace std;
void printBoard(vector<vector<char>>&board){
    int n=board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"---------------------------------------------------------"<<endl;
}
bool inBoard(int i,int j,int n){
    return i>=0 && i<n && j>=0 && j<n;
}
bool isSafe(vector<vector<char>>&board,int row,int col){
    int n=board.size();
    int i,j;
    //top-left...
    i=row-2,j=col-1;
    if(inBoard(i,j,n) && board[i][j]=='K'){
        return false;
    }
    //top-right...
    i=row-2,j=col+1;
    if(inBoard(i,j,n) && board[i][j]=='K'){
        return false;
    }
    //left-top...
    i=row-1,j=col-2;
    if(inBoard(i,j,n) && board[i][j]=='K'){
        return false;
    }
    //right-top...
    i=row-1,j=col+2;
    if(inBoard(i,j,n) && board[i][j]=='K'){
        return false;
    }
    return true;
}
int kNights(vector<vector<char>>&board,int row){
    int n=board.size();
    if(row==n){
        printBoard(board);
        return 1;
    }
    int count=0;
    for(int j=0;j<n;j++){
        if(isSafe(board,row,j)){
            board[row][j]='K';
            count+=kNights(board,row+1);
            board[row][j]='.';
        }
    }
    return count;
}
int main(){
    int n;
    cout<<"Enter size of Board:";
    cin>>n;
    vector<vector<char>>board(n,vector<char>(n,'.'));
    printBoard(board);
    int count=kNights(board,0);
    cout<<"Total solution:"<<count<<endl;
    return 0;

}