/* Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
 implement it using a program to find which alphabet has maximum number of occurrences and
print it. (Time Complexity = O(n)) (Hint: Use counting sort)*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void MostOccurence(char arr[],int n){
    char freq[26]={0};
    for(int i=0;i<n;i++){
        int idx=arr[i]-'a';
        freq[idx]++;
    }
    char ch='a';
    char ans;
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(freq[i]>max){
            max=freq[i];
            ans=ch;
        }
        ch+=1;
    }
    if(max==1){
        cout<<"No duplicates"<<endl;
    }
    else{
        cout<<"MostOccurence:"<<ans<<endl;
    }
    
}
int main(){
    int n;
    char ch;
    cout<<"Enter n:";
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    MostOccurence(arr,n);
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE4(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}