#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
class Node{
    public:
    unordered_map<char,Node*>children;
    bool endOfWord=false;
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
        Node*  temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){//not found
                temp->children[key[i]]=new Node();
            }
            temp=temp->children[key[i]];
        }
        temp->endOfWord=true;
    }
    string printUniquePrefix(string word){
    string ans="";
    Node* temp=root;
    for(int i=0;i<word.size();i++){
        if(temp->children.count(word[i]) && temp->children.size()==1){
            return ans;
        }
        ans+=word[i];
        temp=temp->children[word[i]];
    }
    return word;
}
};

int main(){
    vector<string>words={"zebra","dog","duck","dove","DOG"};
    Tries trie;
    for(int i=0;i<words.size();i++){
        trie.insert(words[i]);
    }
    vector<string>ans;
    for(int i=0;i<words.size();i++){
        string res=trie.printUniquePrefix(words[i]);
        ans.push_back(res);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<",";
    }
    return 0;
}