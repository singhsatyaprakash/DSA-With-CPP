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
int main(){
    vector<string>words={"the","a","there","their","any","thee"};
    Tries trie;
    for(int i=0;i<words.size();i++){
        trie.insert(words[i]);
    }
    cout<<"\nfound:"<<trie.search("their");
    cout<<"\nfound:"<<trie.search("theirs");
    return 0;
}