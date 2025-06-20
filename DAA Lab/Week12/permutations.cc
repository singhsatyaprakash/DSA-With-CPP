#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void generateAllPermutations(vector<char>& chars, int idx, vector<string>& ans) {
    if(idx == chars.size()) {
        ans.push_back(string(chars.begin(), chars.end()));
        return;
    }
    for(int i = idx; i < chars.size(); i++) {
        swap(chars[idx], chars[i]);
        generateAllPermutations(chars, idx + 1, ans);
        swap(chars[idx], chars[i]); // backtrack
    }
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    vector<char> chars(n);
    cout << "Enter characters (space separated):" << endl;
    for(int i = 0; i < n; i++) {
        cin >> chars[i];
    }
    vector<string> ans;
    generateAllPermutations(chars, 0, ans);

    // Sort lexicographically
    sort(ans.begin(), ans.end());

    cout << "All lexicographically sorted permutations:" << endl;
    int count = 0;
    for(const string& s : ans) {
        cout << s << endl;
        count++;
    }
    cout << "Total: " << count << endl;
    return 0;
}
