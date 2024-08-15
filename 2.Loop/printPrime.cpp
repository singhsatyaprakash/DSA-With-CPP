//Printing prime number b/w 2 to n..
#include<iostream>
using namespace std;
int main(){
    int N;
    cout<<"Enter Number:";
    cin>>N;
for(int i=2; i<=N; i++){
    bool isPrime=true;
    int curr = i; //current number to check for bool isPrime = true;
    for(int j=2; j*j<=i; j++){ 
        if(curr % j == 0){
            isPrime = false;
        }
    }
    if(isPrime) {
        cout << curr << " ";
    }
}
cout << endl;
return 0;
}