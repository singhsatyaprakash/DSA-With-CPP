#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
class Node{
    public:
    unordered_map<char,Node*>children;
    bool endOfWord;
    int freq;
    Node(){
        endOfWord=false;
    }
};
class Tries{
    Node* root;
    public:
    Tries(){
        root=new Node();
        root->freq=-1;
    }
    void insert(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){//if not exist create therir children node
                temp->children[key[i]]= new Node();
                temp->children[key[i]]->freq=1;
            }else{
                temp->children[key[i]]->freq++;
            }
            temp=temp->children[key[i]];//temp ko child par la dege.
        }
        temp->endOfWord=true;
    }
    string getprefix(string key){//O(n*l)
        Node* temp=root;
        string prefix="";
        for(int i=0;i<key.size();i++){
            prefix+=key[i];
            if(temp->children[key[i]]->freq==1){
                break;
            }
            temp=temp->children[key[i]];
        }
        return prefix;
    }
};
void prefixProblem(vector<string>dict){
    Tries trie;
    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }
    for(int i=0;i<dict.size();i++){
        cout<<trie.getprefix(dict[i])<<endl;;
    }
}
int main(){
    vector<string>dicit={"zebra","dog","duck","dove"};
    prefixProblem(dicit);
    return 0;
}