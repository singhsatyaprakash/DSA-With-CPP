#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
class Node{
    public:
    unordered_map<char,Node*>children;
    bool endOfWord;
    Node(){
        endOfWord=false;
    }
};
class Tries{
    Node* root;
    public:
    Tries(){
        root=new Node();
    }
    void insert(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){//if not exist create therir children node
                temp->children[key[i]]= new Node();
            }
            temp=temp->children[key[i]];//temp ko child par la dege.
        }
        temp->endOfWord=true;
    }
    void helper(Node* root,string &ans,string temp){
        for(pair<char,Node*>child:root->children){
           if(child.second->endOfWord){
             temp+=child.first;
            if((temp.size()==ans.size() && temp<ans) ||(temp.size()>ans.size())){
                ans=temp;
            }
            helper(child.second,ans,temp);
            temp=temp.substr(0,temp.size()-1);
           }
        }
    }
    string longestStringWithEOW(){
        string ans="";
        helper(root,ans,"");
        return ans;
    }
};
string longestString(vector<string> dict){
    Tries trie;
    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }
    return trie.longestStringWithEOW();
}
int main(){
    vector<string>words={"a","banana","app","appl","ap","apply","apple"};
    cout<<"Longest Word:"<<longestString(words);
    return 0;
}