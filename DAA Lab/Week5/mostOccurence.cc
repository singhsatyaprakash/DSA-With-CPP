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
    return 0;
}