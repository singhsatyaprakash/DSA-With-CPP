//Sieve of Eratosthenes..(finding all prime numbers upto N)
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    //create a boolean array and initialize all entries as true.
    bool prime[n+1];
    prime[0]=prime[1]=false;

    for(int i=2;i<=n;i++){
        prime[i]=true;
    }
//O(n*log(log(n)))....

    //now start with 2nd element and mark all its multiple as false.
    for(int i=2;i*i<=n;i++){
        if(prime[i]==true){
            //mark all multiples of i as not prime.
            for(int j=2;i*j<=n;j++){
                prime[i*j]=false;
            }
        }
    }

    //print all prime numbers
    for(int i=2;i<=n;i++){
        if(prime[i]==true){
            cout<<i<<" ";
        }
    }cout<<endl;


    return 0;
}