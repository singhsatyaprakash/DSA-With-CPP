#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Comparator to sort items based on price per kg in decreasing order
bool compare(pair<float,int> p1, pair<float,int> p2) {
    return p1.first > p2.first;
}

float MaxValue(vector<int> value, vector<int> weight, int w) {

    // Vector to store price per kg and weight pairs
    vector<pair<float,int>> vec(value.size());

    // Calculate price per kg and store pairs
    for(int i = 0; i < value.size(); i++) {
        vec[i] = make_pair((float)value[i] / (float)weight[i], weight[i]);
    }

    // Sort by price per kg in decreasing order
    sort(vec.begin(), vec.end(), compare);

    // Calculate maximum value
    float totalprice = 0;
    for(int i = 0; i < vec.size(); i++) {
        if(w >= vec[i].second) {
            totalprice += vec[i].second * vec[i].first;
            w -= vec[i].second;
        } else {
            totalprice += w * vec[i].first;
            break;
        }
    }

    return totalprice;
}

int main() {
    vector<int> value = {60, 100, 120};  // Value of each item
    vector<int> weight = {10, 20, 30};   // Weight of each item
    int w = 15;                          // Capacity of the knapsack

    float res = MaxValue(value, weight, w);
    cout << "Maximum value the farmer can sell in one go with weight " << w << " is: " << res << endl;

    return 0;
}
