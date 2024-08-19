#include<iostream>
using namespace std;
int pairFriend(int n){
    //bas case..
    if(n==1||n==2){
        return n;
    }
    // ek insaan ke pass 2 option hai ya tho single rahe ya pair me rahe...

    // if single...f(n-1) rest all are also sigle or pair leave to next call...
    int ans1=pairFriend(n-1);
    //if pair ... then one person out of n can pair with n-1 persons rest remain person are n-2 leave them to next call...f(n-1)
    int ans2=(n-1)*pairFriend(n-2);
    return (ans1+ans2);
    
}
int main(){
    int n;
    cout<<"Enter total friends:";
    cin>>n;
    cout<<"Total no. of ways to pair is:"<<pairFriend(n)<<endl;
    return 0;
}
