#include <iostream>
#include <string>
using namespace std;

void printSubstrings(string str) {
    int n = str.length();
    int count=0;
    for(int start = 0; start < n; start++) {
        for(int end = start; end < n; end++) {
            for(int i = start; i <= end; i++) {
                cout << str[i];
            }
            count++;
            cout << endl;
        }
    }
    cout<<"Total:"<<count<<endl;
}

int main() {
    string str = "RLRRLLRLRL";
    printSubstrings(str);
    return 0;
}
