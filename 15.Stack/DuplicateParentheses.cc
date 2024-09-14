#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool checkDuplicate(string str){
    //valid expression is given..
    stack<char>s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch!=')'){//non-closing
            s.push(ch);
        }
        else{
            if(s.top()=='('){//imdiate found without bundle b/w them 
                return true;//duplicate exist...
            }
            while(s.top()!='('){
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}
int main(){
    string str;
    cout<<"Enter string:";
    getline(cin,str);
    bool res=checkDuplicate(str);
    if(res){
        cout<<"Duplicate present."<<endl;
    }
    else{
        cout<<"NO Duplicate present."<<endl;
    }
    return 0;
}