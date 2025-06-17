#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


float MaxValue(vector<int> value, vector<int> weight, int w) {

    // Vector to store price per kg and weight pairs
    vector<pair<float,int>> vec(value.size());

    // Calculate price per kg and store pairs
    for(int i = 0; i < value.size(); i++) {
        vec[i] = make_pair((float)value[i] / (float)weight[i], weight[i]);
    }

    // Sort by price per kg in decreasing order
    sort(vec.rbegin(), vec.rend());

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
    int n;
    cout<<"Enter total item:"<<endl;
    cin>>n;
    vector<int>value;
    vector<int>weight;
    int val,wt;
    cout<<"Enter value,weight:"<<endl;
    for(int i=0;i<n;i++){
        cin>>val>>wt;
        value.push_back(val);
        weight.push_back(wt);
    }
    int w;
    cout<<"Enter capacity of knapsack:"<<endl;
    cin>>w;
    float res = MaxValue(value, weight, w);
    cout << "Maximum value for " << w << " is: " << res << endl;

    return 0;
}
