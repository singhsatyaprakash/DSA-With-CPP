#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int i, int prev,vector<pair<int, int>>& players, vector<vector<int>>& dp) {
    if (i ==players.size()){
        return 0;
    }
    if(dp[i][prev+1]!=-1){
        return dp[i][prev+1];
    }

    int notTake = solve(i + 1, prev, players, dp);

    int take = 0;
    if (prev == -1 || players[prev].second<= players[i].second) {
        take = players[i].second + solve(i + 1, i, players, dp);
    }

    return dp[i][prev+1] = max(take, notTake);
}

int bestTeamScoreRecursive(vector<int>& scores, vector<int>& ages) {
    int n = scores.size();
    vector<pair<int, int>> players;

    for (int i = 0; i < n; i++) {
        players.push_back({ages[i], scores[i]});
    }

    sort(players.begin(), players.end()); // sort by age, then score...

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(0, -1, players, dp);
}

int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int n = scores.size();
    vector<pair<int, int>> players;
    for (int i = 0; i < n; i++) {
        players.push_back({ages[i], scores[i]});
    }

    sort(players.begin(), players.end()); // sort by age, then score

    vector<int> dp(n, 0);
    int ans = 0;

    // dp[i] = best team score ending with player i included
    for (int i = 0; i < n; i++) {
        dp[i] = players[i].second; //take i alone..
        for (int j = 0; j < i; j++) { // who can be with i...
            if (players[j].second <= players[i].second) {
                dp[i] = max(dp[i], dp[j] + players[i].second);
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main() {
    int n;
    cout<<"Enter n:";
    cin >> n;

    vector<int> ages(n), scores(n);
    cout<<"Enter scores:"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    cout<<"Enter ages:"<<endl;
    for (int i = 0; i < n; i++){
        cin >> ages[i];
    }

    // cout << bestTeamScoreRecursive(scores, ages);
    cout << bestTeamScore(scores, ages);
    return 0;
}