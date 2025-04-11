#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& allSubsets) {
    if (index == nums.size()) {
        allSubsets.push_back(current);
        return;
    }

    // Include nums[index]
    current.push_back(nums[index]);
    helper(nums, index + 1, current, allSubsets);

    // Exclude nums[index]
    current.pop_back();
    helper(nums, index + 1, current, allSubsets);
}

void generateSubsets(vector<int>& nums) {
    vector<vector<int>> allSubsets;
    vector<int> current;
    helper(nums, 0, current, allSubsets);

    for (auto& subset : allSubsets) {
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    }
}
int main(){
    vector<int>nums={5,1,6};
    generateSubsets(nums);
}