#include<iostream>
#include<vector>
using namespace std;
//O(N)...
// bool isPrime(int num){
//      if(n==0 || n==1) return false;
//     for(int fact=2;fact<num;fact++){
//         if(num%fact==0){
//             return false;
//         }
//     }
//     return false;
// }

//O(root N)..
bool isPrime(int num){
    for(int fact=2;fact*fact<=num;fact++){
        if(num%fact==0){
            return false;
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    if(isPrime(n)){
        cout<<n<<" is prime Number.."<<endl;
    }
    return 0;
}