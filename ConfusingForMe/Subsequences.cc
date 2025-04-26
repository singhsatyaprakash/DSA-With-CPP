#include <iostream>
#include <string>
using namespace std;

void printSubsequences(string str) {
    int n = str.length();
    int total = 1 << n; // 2^n subsequences
    for(int mask = 0; mask < total; mask++) {
        for(int i = 0; i < n; i++) {
            // cout<<(mask & (1 << i));
            if(mask & (1 << i)) {
                cout << str[i];
            }
        }
        cout << endl;
    }
}

int main() {
    string str = "abc";
    printSubsequences(str);
    return 0;
}
