// C++ program to search the pattern in given text using
// KMP Algorithm

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void constructLps(string &pat, vector<int> &lps) {

    // len stores the length of longest prefix which
    // is also a suffix for the previous index
    int len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    int i = 1;
    while (i < pat.length()) {

        // If characters match, increment the size of lps
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }

        // If there is a mismatch
        else {
            if (len != 0) {

                // Update len to the previous lps value
                // to avoid reduntant comparisons
                len = lps[len - 1];
            }
            else {

                // If no matching prefix found, set lps[i] to 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string &pat, string &txt) {
    int n = txt.length();
    int m = pat.length();

    vector<int> lps(m);
    vector<int> res;

    constructLps(pat, lps);

    // Pointers i and j, for traversing
    // the text and pattern
    int i = 0;
    int j = 0;

    while (i < n) {

        // If characters match, move both pointers forward
        if (txt[i] == pat[j]) {
            i++;
            j++;

            // If the entire pattern is matched
            // store the start index in result
            if (j == m) {
                res.push_back(i - j);

                // Use LPS of previous index to
                // skip unnecessary comparisons
                j = lps[j - 1];
            }
        }

        // If there is a mismatch
        else {

            // Use lps value of previous index
            // to avoid redundant comparisons
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}

int main() {
    string txt, pat;
    cout << "Enter the text: ";
    getline(cin, txt);
    cout << "Enter the pattern to search: ";
    getline(cin, pat);

    vector<int> res = search(pat, txt);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> buildLPS(string pattern) {
//     int m = pattern.length();
//     vector<int> lps(m, 0);
//     int len = 0;
//     for (int i = 1; i < m;) {
//         if (pattern[i] == pattern[len]) {
//             lps[i++] = ++len;
//         } else if (len != 0) {
//             len = lps[len - 1];
//         } else {
//             lps[i++] = 0;
//         }
//     }
//     return lps;
// }

// void printLPS(const vector<int>& lps) {
//     cout << "LPS Array: ";
//     for (int i = 0; i < lps.size(); i++) {
//         cout << lps[i] << " ";
//     }
//     cout << endl;
// }

// void KMPSearch(string text, string pattern) {
//     if (pattern.empty()) {
//         cout << "Pattern is empty. No search performed." << endl;
//         return;
//     }

//     vector<int> lps = buildLPS(pattern);
//     printLPS(lps);

//     int i = 0, j = 0;
//     int n = text.length();
//     int m = pattern.length();
//     bool found = false;

//     while (i < n) {
//         if (text[i] == pattern[j]) {
//             i++; j++;
//         }

//         if (j == m) {
//             cout << "Pattern found at index " << i - j << endl;
//             found = true;
//             j = lps[j - 1]; // Continue to check for next match
//         } else if (i < n && text[i] != pattern[j]) {
//             j = (j != 0) ? lps[j - 1] : 0;
//         }
//     }

//     if (!found) {
//         cout << "Pattern not found in the text." << endl;
//     }
// }

// int main() {
//     string text, pattern;
//     cout << "Enter the text: ";
//     getline(cin, text);
//     cout << "Enter the pattern to search: ";
//     getline(cin, pattern);

//     KMPSearch(text, pattern);
//     return 0;
// }
