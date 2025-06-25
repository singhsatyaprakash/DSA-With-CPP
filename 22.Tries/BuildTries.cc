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
    // Helper for hard delete
    bool hardDeleteHelper(Node* node, const string& key, int depth) {
        if (!node) return false;
        if (depth == key.size()) {
            if (!node->endOfWord) return false; // word not found
            node->endOfWord = false; // Unmark end of word
            return node->children.empty(); // If no children, node can be deleted
        }
        char ch = key[depth];
        if (node->children.count(ch) == 0) return false; // char not found
        bool shouldDeleteChild = hardDeleteHelper(node->children[ch], key, depth + 1);
        if (shouldDeleteChild) {
            delete node->children[ch];
            node->children.erase(ch);
            return !node->endOfWord && node->children.empty();
        }
        return false;
    }
public:
    Tries(){
        root=new Node();
    }
    void insert(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){//if not exist create their children node
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
    // Soft delete: just unmark endOfWord
    void softDelete(const string& key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) return; // word not found
            temp = temp->children[key[i]];
        }
        temp->endOfWord = false;
    }
    // Hard delete: remove nodes if not needed
    void hardDelete(const string& key) {
        hardDeleteHelper(root, key, 0);
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

    // Soft delete example
    trie.softDelete("their");
    cout<<"\nAfter soft delete, found their: "<<trie.search("their");

    // Hard delete example
    trie.hardDelete("thee");
    cout<<"\nAfter hard delete, found thee: "<<trie.search("thee");

    return 0;
    
}