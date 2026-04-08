#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    //Detect cycle
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    //Find duplicate (cycle entry)
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter elements: ";
    vector<int> nums(n);
    cout << findDuplicate(nums);
    return 0;
}