#include<iostream>
#include<string>
using namespace std; 
string reverse(string s,int n){
    int i=0,j=n-1;
    while(i<j){
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
        if(s[j]=='('){
            s[j]=')';
        }
        else if(s[j]==')'){
            s[j]='(';
        }
        swap(s[i],s[j]);
        i++;
        j--;
    }
    return s;
}
bool isStackEmpty(int *top){
    if(*top==-1){
        return true;//stack is empty..
    }
    else{
        return false;//stack not empty..
    }
}
void push(char arr[],char ch,int *top){
    arr[++(*top)]=ch;
    return;
}
void pop(char arr[],int *top){
    (*top)--;
}
//return top element of stack
char topEle(char st[],int *top){
    return st[(*top)];
}
int pres(char c) {
    switch(c) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        default: return 0;
    }
}
int main(){
    string s;
    string ans="";
    cout<<"Enter Infix Expression:"<<endl;
    getline(cin,s);
    int n=s.length();
    char st[n];//creating stack
    int top=-1;
    //reversing th expression and changeing symbol of brackets...
    s=reverse(s,n);//string are passed by value in c++...
    
    for(int i=0;i<n;i++){
        char ch=s[i];
        //if incoming charcater is an operand ,output it..ans
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            ans+=ch;
        }
        else if(ch=='('){
            push(st,ch,&top);
        }
        else if(ch==')'){
            while(!isStackEmpty(&top) && topEle(st,&top)!='('){
                ans+=topEle(st,&top);
                pop(st,&top);
            }
            pop(st,&top); //remove '('
        }
        else {
            while(!isStackEmpty(&top) && pres(topEle(st,&top))>=pres(ch)){
                ans+=topEle(st,&top);
                pop(st,&top);
            }
            push(st,ch,&top);
        }
    }
    //pop all...
    while(!isStackEmpty(&top)){
        ans+=topEle(st,&top);
        pop(st,&top);
    }
    int m=ans.size();
    ans=reverse(ans,m);
    cout<<"Prefix Experssion :";
    cout<<ans<<endl;
    return 0;
}