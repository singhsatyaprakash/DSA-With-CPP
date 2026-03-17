#include<iostream>
using namespace std;
//Time: O(√n)...
bool isPrime(int n){
    if(n==0 || n==1){
        return false;
    }
    for(int fact=2;fact*fact<=n;fact++){
        if(n%fact==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    bool res=isPrime(n);
    if(res){
        cout<<n<<" is prime number."<<endl;
    }
    else{
        cout<<n<< " is not a prime number."<<endl;
    }
    return 0;
}