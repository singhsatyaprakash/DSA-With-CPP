#include <iostream>
#include <vector>

using namespace std;

int get_max_prefix(int N, vector<int> E) {
    int safe_prefix = 1;
    int max_prefix = 1;
    bool bubbling = false;

    for (int i = 1; i < N; ++i) {
        if (E[i - 1] <= E[i]) {
            // Elements are naturally non-decreasing
            max_prefix = i + 1;
            safe_prefix = max_prefix;
            bubbling = false;
        } else {
            // We have a violation, begin transferring (swapping)
            if (!bubbling) {
                safe_prefix = max_prefix; // Remember the length before we started altering the array
                bubbling = true;
            }

            // Transferring E[i-1] - E[i] units is mathematically equivalent to swapping them
            int temp = E[i - 1];
            E[i - 1] = E[i];
            E[i] = temp;

            // Check if reducing E[i-1] broke the previously established non-decreasing order
            if (i - 2 >= 0 && E[i - 2] > E[i - 1]) {
                return safe_prefix; 
            }

            max_prefix = i + 1;
        }
    }

    return max_prefix;
}

// Boilerplate main function matches the one in your images
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // Read input (assuming proper reading logic as per the platform's boilerplate)
    int N;
    if (!(cin >> N)) return 0;
    
    vector<int> E(N);
    for (int j = 0; j < N; j++) {
        cin >> E[j];
    }
    
    cout << get_max_prefix(N, E) << "\n";
    
    return 0;
}