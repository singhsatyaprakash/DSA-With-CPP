#include<iostream>
#include<string>
using namespace std;

void push(string st[],int *top,string ans){
    (*top)++;
    st[*top]=ans;
}

string pop(string st[],int *top){
    if(*top==-1){
        return "";
    }
    string str=st[*top];
    (*top)--;
    return str;
}

bool isStackEmpty(int *top){
    if(*top==-1){
        return true;
    }else{
        return false;
    }
}

int main(){
    string s;
    cout<<"Enter Prefix Expression:"<<endl;
    getline(cin,s);   
    int n=s.size();
    string st[n];
    int top=-1;
    // Reading the expression in reverse order
    for(int i=n-1;i>=0;i--){
        char ch=s[i];
        //if the symbol is an opreand,then push it onto stack..        
        if((ch>='A' && ch<='Z')||(ch>='a' && ch<='z')||(ch>='0' && ch<='9')){
            string ans="";
            ans+=ch;
            push(st,&top,ans);
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            if(!isStackEmpty(&top)){
                string str1=pop(st,&top);
                if(!isStackEmpty(&top)){
                    string str2=pop(st,&top);
                    string ans="(" + str1 + ch + str2 + ")";
                    push(st,&top,ans);
                }
            }
        }
    }
    cout<<"Infix Expression:"<<endl;
    cout<<pop(st,&top)<<endl;
    return 0;
}
