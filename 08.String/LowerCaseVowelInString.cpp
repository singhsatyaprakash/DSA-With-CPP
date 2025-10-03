//Count how many times lowercase vowels occurred in a String entered by the user.
#include<iostream>
#include<string>
using namespace std;
int VolCount(string str){
    int count=0;
    for(char ch:str){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            count++;
        }
    }
    return count;
}
int main(){
    string input;
    cout<<"Enter string:";
    getline(cin,input);
    cout<<"Total no. of lowers case vowel occured is:"<<VolCount(input)<<endl;
    return 0;
}