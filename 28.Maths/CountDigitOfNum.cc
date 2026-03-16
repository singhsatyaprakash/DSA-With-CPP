#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;

    int temp = n;
    int count=0;

    // O(number of digits)
    while(temp > 0){
        count++;
        temp = temp/10;
    }

    cout<<"Total digit in number: "<<count<<endl;

    // O(1)
    cout<<"Total digit in number: "<<floor(log10(n)) + 1<<endl;

    return 0;
}