#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void maxTasks(int n, vector<int>& times, vector<int>& deadlines) {
    vector<pair<pair<int, int>, int>> tasks; // {{deadline, time}, index}
    
    for (int i = 0; i < n; ++i) {
        tasks.push_back({{deadlines[i], times[i]}, i + 1});
    }

    // Sort by deadline
    sort(tasks.begin(), tasks.end());

    priority_queue<pair<int, int>> maxHeap; // {time, index}
    int totalTime = 0;

    for (auto& task : tasks) {
        int deadline = task.first.first;
        int time = task.first.second;
        int index = task.second;

        if (totalTime + time <= deadline) {
            maxHeap.push({time, index});
            totalTime += time;
        } else if (!maxHeap.empty() && maxHeap.top().first > time) {
            totalTime -= maxHeap.top().first;
            maxHeap.pop();
            maxHeap.push({time, index});
            totalTime += time;
        }
    }

    // Extract and sort selected task indices
    vector<int> selected;
    while (!maxHeap.empty()) {
        selected.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    sort(selected.begin(), selected.end());

    // Output
    cout << "Max number of tasks = " << selected.size() << endl;
    cout << "Selected task numbers : ";
    for (size_t i = 0; i < selected.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << selected[i];
    }
    cout << endl;
}

int main() {
    int n;
    cout<<"Enter no. of activites:";
    cin>>n;
    vector<int> times(n), deadlines(n);
    cout<<"Enter Times:"<<endl;
    for (int i = 0; i < n; ++i) cin >> times[i];
    cout<<"Enter deadlines:"<<endl;
    for (int i = 0; i < n; ++i) cin >> deadlines[i];

    maxTasks(n, times, deadlines);
    return 0;
}