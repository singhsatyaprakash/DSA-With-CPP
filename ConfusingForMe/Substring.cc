#include <iostream>
#include <string>
using namespace std;

void printSubstrings(string str) {
    int n = str.length();
    for(int start = 0; start < n; start++) {
        for(int end = start; end < n; end++) {
            for(int i = start; i <= end; i++) {
                cout << str[i];
            }
            cout << endl;
        }
    }
}

int main() {
    string str = "abc";
    printSubstrings(str);
    return 0;
}
