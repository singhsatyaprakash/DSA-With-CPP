#include<iostream>
#include<utility>//for pair
#include<string>
#include<queue>
#include<vector>
using namespace std;
int main(){
    priority_queue<pair<string,int>>pq;    //for max heap..
    pq.push(make_pair("Apoorva",95));
    pq.push(make_pair("Satya",92));
    pq.push(make_pair("Deepak",90));
    pq.push(make_pair("Saurabh",99));
    while(!pq.empty()){
        cout<<pq.top().first<<endl;
        pq.pop();
    }
    return 0;
}
/*
#include <iostream>
#include <vector>  // For the vector container
#include <string>
#include <queue>
#include <utility> // For std::pair

using namespace std;

// Custom comparator for the min heap
struct ComparePair {
    bool operator ()(pair<string, int>& p1, pair<string, int>& p2) {
        return p1.second < p2.second; // Min heap: higher second values have higher priority
    }
};

int main() {
    // Priority queue for min heap using the custom comparator
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;
    
    pq.push(make_pair("Apoorva", 95));
    pq.push(make_pair("Satya", 92));
    pq.push(make_pair("Deepak", 90));
    pq.push(make_pair("Saurabh", 99));
    
    // Print elements in priority order (min-heap, so lowest value comes first)
    while (!pq.empty()) {
        cout << pq.top().first << endl;
        pq.pop();
    }

    return 0;
}
