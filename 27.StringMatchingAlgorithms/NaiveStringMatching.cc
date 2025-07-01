#include<iostream>
using namespace std;
void naiveSearch(string text, string pattern) { //O(n*m) time complexity
    int n = text.size(), m = pattern.size();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}
int main(){
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);
    naiveSearch(text, pattern);
    return 0;
}
