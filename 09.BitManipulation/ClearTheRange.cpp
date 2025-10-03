/*Write a Function to clear the range of bits from i to j in a given number. (i & j are counted backwards from the right end of the number)
Examples :
Input : num = 15, i = 1, j = 3 Output : 1
Explanation :
15 in binary form is => 00001111 [i=1st & j=3rd bit underlined] After bits are cleared, number will become 00000001
Input : num = 31, i = 1, j = 3 Output : 17
Note - Think about what type of bit mask is needed. It can also be a combination of 2 numbers.
*/
#include<iostream>
using namespace std;  
int ClearTheRange(int num,int m,int n){
    for(int i=m;i<=n;i++){
        int bitmask=~(1<<i);
        num = num & bitmask; 
    }
    return num;
}
int main(){
    int num,i,j;
    cout<<"Enter Num:";
    cin>>num;
    cout<<"Enter range from i to j:";
    cin>>i>>j;
    cout<<ClearTheRange(num,i,j)<<endl;;
    return 0;
}