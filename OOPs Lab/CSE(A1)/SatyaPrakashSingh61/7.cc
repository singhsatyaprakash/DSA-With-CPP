/*.
Construct a C++ program that removes a specific character from a given string and return the updated string.
Input: computer science is the future
Output: compuer science is he fuure
*/
#include<iostream>
#include<string>
using namespace std;
string removeCharacter(string str,char ch){
    int i,j=0;
    int len=str.size();
    for(i=0;i<len;i++){
        if(str[i]!=ch){
            str[j++]=str[i];
        }
    }
    str[j] = '\0';//for new string end..
    return str;
}

int main(){
    string str;
    cout<<"Enter String: ";
    getline(cin,str);
    char ch;
    cout<<"Enter character to remove: ";
    cin>>ch;
    str=removeCharacter(str,ch);
    cout<<"Updated string: "<<str<<endl;
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}
