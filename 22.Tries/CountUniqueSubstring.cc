#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Node{
public:
    bool eow;
    unordered_map<char,Node*>children;
    Node(){
        eow=false;
    }
};
class Tries{
    Node* root;
    public:
    Tries(){
        root=new Node();
    }
    void insert(string key){
        // cout<<key<<endl;
        Node* temp=root;
        for(auto ch:key){
            if(temp->children.count(ch)==0){
                temp->children[ch]=new Node();
            }
            temp=temp->children[ch];
        }
        temp->eow=true;
    }
    int helper(Node* root){
        int count=0;
        for(auto it:root->children){
            count+= helper(it.second);
        }
        return count+1;
    }
    int countNode(){
        Node* temp=root;
        return helper(temp);
    }
};
void getsuffix(string key, vector<string>& suffix) {
    int n = key.size();
    for (int i = 0; i < n; i++) {
        suffix.push_back(key.substr(i));
    }
}

int main(){
    string str;
    cout<<"Enter string:";
    getline(cin,str);
    vector<string>suffix;
    getsuffix(str,suffix);
    // for(int i=0;i<suffix.size();i++){
    //     cout<<suffix[i]<<endl;
    // }
    Tries trie;
    for(auto &suf:suffix){
        trie.insert(suf);
    }
    cout<<trie.countNode()<<endl;
    return 0;

}