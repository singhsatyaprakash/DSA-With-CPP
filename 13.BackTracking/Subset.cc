#include<iostream>
#include<string>
using namespace std;
void printSubsets(string str,string subset){
    if(str==""){//str.size()==0
        cout<<subset<<endl;
        return;
    }
    char ch=str[0]; 
    //yes choice
    printSubsets(str.substr(1,str.size()-1),subset+ch);
    //no choice
    printSubsets(str.substr(1,str.size()-1),subset);
}
int main(){
    string str;
    cout<<"Enter string:"; 
    string subset=""; 
    getline(cin,str);
    printSubsets(str,subset);
    return 0; 
}

// #include <iostream>
// #include <vector>
// using namespace std;

// void generateSubsets(string str, string current, int index) {
//     if (index == str.length()) {
//         cout << current << endl;
//         return;
//     }

//     // Include the current character
//     generateSubsets(str, current + str[index], index + 1);

//     // Exclude the current character
//     generateSubsets(str, current, index + 1);
// }

// int main() {
//     string str = "aabcb";
//     generateSubsets(str, "", 0);
//     return 0;
// }
