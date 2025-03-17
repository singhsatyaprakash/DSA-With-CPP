#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
struct Node{
    char ch;
    int freq;
    Node* left,*right;
};
Node* getNode(char ch,int freq,Node* left,Node* right){
    Node* newnode=new Node();
    newnode->ch=ch;
    newnode->freq=freq;
    newnode->left=left;
    newnode->right=right;
    return newnode;
}
struct Minheap{
    Node* heap[1000];
    int size;
    Minheap(){
        size=0;
    }
    void heapify(int i) { 
        int minIdx=i; 
        int left=2*i; 
        int right=2*i+1; 
        if(left<=size && heap[left]->freq < heap[minIdx]->freq){ 
            minIdx= left; 
        }
        if(right <= size && heap[right]->freq < heap[minIdx]->freq){
            minIdx = right; 
        }
        if(minIdx!=i){ 
            swap(heap[i], heap[minIdx]); 
            heapify(minIdx); 
        } 
    }  
    void insert(Node* node) { 
        size++; 
        int i=size; 
        heap[i]=node; 
        while(i>1 && heap[i]->freq < heap[i / 2]->freq) { 
            swap(heap[i], heap[i / 2]); 
            i = i / 2; 
        } 
    }
    Node* extractMin() { 
        Node* minNode = heap[1]; 
        heap[1] = heap[size]; 
        size--; 
        heapify(1); 
        return minNode; 
    } 
};
void encode(Node* root,string str,unordered_map<char,string>&huffmanCode){
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr && root->right==nullptr){
        huffmanCode[root->ch]=str;
    }
    encode(root->left,str+"0",huffmanCode);
    encode(root->right,str+"1",huffmanCode);
}
// Function to decode a Huffman encoded string 
void decode(Node* root,int& index,string str){ 
    if(root==nullptr){
        return;
    } 
    if(root->left==nullptr && root->right==nullptr){ 
        cout << root->ch; 
        return; 
    }
    index++; 
    if(str[index]=='0'){ 
        decode(root->left, index, str);
    } 
    else{ 
        decode(root->right, index, str);
    } 
}
//function to build Huffman Tree and perform encoding and decoding
void bulidHuffmanTree(string text){
    unordered_map<int,char>m;
    for(auto ch:text){
        m[ch]++;
    }
    Minheap minheap;
    for(auto pair:m){
        minheap.insert(getNode(pair.first,pair.second,nullptr,nullptr));
    }
    while(minheap.size>1){
        Node* left=minheap.extractMin();
        Node* right=minheap.extractMin();
        Node* sumNode=getNode('\0',left->freq+right->freq,left,right);
        minheap.insert(sumNode);
    }
    Node* root=minheap.extractMin();
    unordered_map<char,string>huffmanCode;
    encode(root,"",huffmanCode);
    cout<<"Encoding Chart:"<<endl;
    for(auto it:huffmanCode){
        cout<<it.first<<" "<<it.second<<endl;
    }

    string encodedString = ""; 
    for(char ch:text){
        encodedString += huffmanCode[ch];
    } 
    cout<<"Encoded String: "<<encodedString<<endl; 
    int index=-1; 
    cout<<"Decoded String: "; 
    while(index<(int)encodedString.size()-2){ 
        decode(root, index, encodedString);
    } 
    cout << "\n"; 
}
int main(){
    string text;
    cout<<"Enter Text:"<<endl;
    getline(cin,text);
    bulidHuffmanTree(text);
    return 0;
}