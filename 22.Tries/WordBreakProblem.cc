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
    bool search(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])){//found move to next.
                temp=temp->children[key[i]];
            }
            else{
                return false;
            }
        }
        return temp->endOfWord;
    }
};
bool helper(Tries &trie,string key){
    if(key.size()==0){
        return true;
    }
    for(int i=0;i<key.size();i++){
        string first=key.substr(0,i+1);
        string second=key.substr(i+1);
        if(trie.search(first) && helper(trie,second)){
            return true;
        }
    }
    return false;
}
bool wordBreak(vector<string>words,string key){
    Tries trie;
    for(int i=0;i<words.size();i++){
        trie.insert(words[i]);
    }
    return helper(trie,key);
}
int main(){
    vector<string>words={"i","like","sam","samsung","mobile","ice"};
    string key="ilikesamsung";
    cout<<"Is possible?:"<<(wordBreak(words,key)?("Yes"):("No"));
    return 0;
}