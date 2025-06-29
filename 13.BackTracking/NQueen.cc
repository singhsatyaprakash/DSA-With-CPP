#include<iostream>
#include<vector>
using namespace std;
void printBoard(vector<vector<char>>board){
    int n=board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(vector<vector<char>>&board,int row,int col){
    int n=board.size();
    //horizontally...
    for(int j=0;j<n;j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
    //vertically...
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }

    //diagonally left
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    //diagonally right
    for(int i=row,j=col;i>=0 && j<=n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
void nQueens(vector<vector<char>>&board,int row,int &count){
// bool nQueens(vector<vector<char>>&board,int row,int &count){
    int n=board.size();
    if(row==n){
        cout<<"------------------------------------"<<endl;
        count++;
        printBoard(board); 
        return;
        // return true;
    }
    for(int j=0;j<n;j++){
        if(isSafe(board,row,j)){
            board[row][j]='Q';
            // if(nQueens(board,row+1,count)){
            //     return true;
            // };
            nQueens(board,row+1,count);
            board[row][j]='.';
        }
    }
    // return false;
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<vector<char>>board(n,vector<char>(n,'.'));
    //printBoard(board);
    int count=0;//possible combination
    nQueens(board,0,count);
    cout<<"Total Combination are:"<<count<<endl;
}