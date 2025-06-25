#include <iostream>
#include <list>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

class HashNode {
public:
    string key;
    int value;

    HashNode(string k, int v) {
        key = k;
        value = v;
    }
};

class HashTable {
private:
    list<HashNode*> table[TABLE_SIZE];

    int hashFunction(string key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % TABLE_SIZE;
        }
        return hash;
    }

public:
    void insert(string key, int value) {
        int index = hashFunction(key);

        // Check if key already exists
        for (auto node : table[index]) {
            if (node->key == key) {
                node->value = value;  // Update
                return;
            }
        }

        // Else insert new node
        table[index].push_back(new HashNode(key, value));
    }

    int search(string key) {
        int index = hashFunction(key);
        for (auto node : table[index]) {
            if (node->key == key) {
                return node->value;
            }
        }
        return -1;  // Not found
    }

    void remove(string key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if ((*it)->key == key) {
                delete *it;
                table[index].erase(it);
                return;
            }
        }
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto node : table[i]) {
                cout << "[" << node->key << ": " << node->value << "] -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;
    ht.insert("apple", 10);
    ht.insert("banana", 20);
    ht.insert("orange", 30);
    ht.insert("grape", 40);

    cout << "Search orange: " << ht.search("orange") << endl;

    ht.remove("banana");

    cout << "\nHash Table:\n";
    ht.display();

    return 0;
}
