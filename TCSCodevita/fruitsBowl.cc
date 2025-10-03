#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Cross product of (O→A) × (O→B)
long long cross(pair<int,int> O, pair<int,int> A, pair<int,int> B) {
    return 1LL * (A.first - O.first) * (B.second - O.second) -
           1LL * (A.second - O.second) * (B.first - O.first);
}

// Euclidean distance between two points
double dist(pair<int,int> A, pair<int,int> B) {
    return sqrt(1.0 * (A.first - B.first) * (A.first - B.first) +
                1.0 * (A.second - B.second) * (A.second - B.second));
}

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> points;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    // sort by x, then y
    sort(points.begin(), points.end());

    vector<pair<int,int>> bowl; // lower hull

    for (int i = 0; i < n; i++) {
        // ensure convex shape: remove last point if it makes a "right turn"
        while (bowl.size() >= 2 && cross(bowl[bowl.size()-2], bowl.back(), points[i]) <= 0) {
            bowl.pop_back();
        }
        bowl.push_back(points[i]);
    }

    // calculate perimeter
    double perimeter = 0.0;
    for (int i = 1; i < (int)bowl.size(); i++) {
        perimeter += dist(bowl[i-1], bowl[i]);
    }

    // print bowl points
    cout << "Bowl points:\n";
    for (auto &p : bowl) {
        cout << p.first << " " << p.second << "\n";
    }

    cout << "Perimeter = " << (int)perimeter << "\n";

    return 0;
}
