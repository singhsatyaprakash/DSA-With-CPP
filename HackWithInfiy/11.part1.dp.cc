#include <bits/stdc++.h>
using namespace std;

int longestPathForK(vector<int>& p, int k) {
    int n = p.size();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
            if (j == i) continue;
            if (p[j] < p[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int solve(vector<int>& p, int m) {
    int n = p.size();

    if (m <= 1) return 0;

    int low = 1, high = n - 1, ans = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (longestPathForK(p, mid) >= m) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << solve(p, m) << '\n';
    return 0;
}