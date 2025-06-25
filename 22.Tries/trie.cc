#include <iostream>

using namespace std;

struct node{
    bool isWord;
    node *child[26];
};

node* newnode()
{
    node *temp = (node *)malloc(sizeof(node));
    temp->isWord = false;
    for(int i = 0; i < 26; i++){
        temp->child[i] = NULL;
    }
    return temp;
}

void insert(node *root, string str)
{
    int n = str.length();
    for(int i = 0; i < n; i++)
    {
        if(root->child[str[i] - 'a'] == NULL)
            root->child[str[i] - 'a'] = newnode();
        root = root->child[str[i]-'a'];
    }
    root->isWord = true;
}

bool search(node *root, string str)
{
    int n = str.length();
    for(int i = 0; i < n; i ++)
    {
        if(root->child[str[i] - 'a'] == NULL)
        {
            cout<<"Node not present\n";
            return false;
        }
        root = root->child[str[i] - 'a'];
    }
    if(root->isWord == false){
        cout<<"Isword is false\n";
    }
    return root->isWord;
}

void delete1(node *root, string str) //soft delete
{
    int n = str.length();
    for(int i = 0; i < n; i++)
    {
        if(root->child[str[i]-'a'] == NULL) return;
        root = root->child[str[i] - 'a'];
    }
    root->isWord = false;
}

bool check(node *root)
{
    for(int i = 0; i < 26; i++)
    {
        if(root->child[i] != NULL) return false;
    }
    return !root->isWord;
}

node* deleteUtils(node *root, string str, int n, int i)
{
    if(i == n)
    {
        root->isWord = false;
        if(check(root))
        {
            free(root);
            return NULL;
        }
        else{
            return root;
        }
    }
    node *temp = deleteUtils(root->child[str[i] - 'a'], str, n, i+1);
    if(temp == NULL)
    {
        root->child[str[i] - 'a'] = NULL;
        if(check(root)){
            free(root);
            return NULL;
        }
    }
    return root;
}

void delete2(node *root, string str)//hard delete
{
    int n = str.length();
    deleteUtils(root, str, n, 0);
}

int main()
{
    int Q, ch;
    node *root = newnode();
    string str;
    cin>>Q;
    while(Q--)
    {
        cout<<"Menu\n1. Insert\n2. Searching\n3. delete\nEnter choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: cin>>str;
                    insert(root, str);
                    break;
            case 2: cin>>str;
                    if(search(root, str))
                        cout<<str<<" is in Trie\n";
                    else
                        cout<<str<<" is not in Trie\n";
                    break;
            case 3: cin>>str;
                    if(search(root,str)) delete2(root, str);
                    break;
        }
    }

}
