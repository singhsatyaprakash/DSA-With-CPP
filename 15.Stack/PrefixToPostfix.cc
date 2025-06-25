#include<iostream>
using namespace std;
void push(string st[], int *top,string ans) {
    (*top)++;
    st[*top]=ans;
}
string pop(string st[], int *top) {
    string str=st[*top];
    (*top)--;
    return str;
}

// Function to convert prefix to postfix..
string postfixToPrefix(string s,int n){
    string st[n];//creating stack..
    int top=-1;
    // Traversing the prefix expression 
    for (int i=n-1;i>=0;i--){//READ reverse
        char ch=s[i];
        //If the character is an operand then push..
        if((ch>='A'&& ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0' && ch<='9')){
            string ans="";
            ans +=ch;
            push(st,&top,ans);
        }
        // If the character is an operator pop two operand then conacetenate and push to stack...
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            string str1= pop(st,&top);
            string str2= pop(st,&top);
            //concat operator after two operand str1 and str2.. 
            string ans="";
            ans+=str1;
            ans+=str2;
            ans+=ch;
            // Push the resultant string back to the stack...
            push(st,&top,ans);
        }
    }
    return pop(st,&top);;
}
int main() {
    string s;
    cout<<"Enter Prefix Expression:"<<endl;
    getline(cin,s);
    int n=s.size();
    string ans=postfixToPrefix(s,n);
    cout<<"Postfix Expression: "<<endl;
    cout<<ans<<endl;
    return 0;
}
