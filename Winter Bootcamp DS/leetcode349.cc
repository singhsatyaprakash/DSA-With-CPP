/*Given two integer arrays nums1 and nums2, return an array of their 
intersection. Each element in the result must be unique and you may return the result in any order.*/
#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    void intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1;
        vector<int>ans;
        for( auto el:nums1){
            s1.insert(el);
        }
        for(auto el:nums2){
            if(s1.find(el)!=s1.end()){//found
                ans.push_back(el);
                s1.erase(el);
            }
        }
        cout<<"Intersection of Array:"<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
};
int main(){
    Solution sc;
    vector<int>nums1={1,2,4,5};
    vector<int>nums2={4,5,6,7};
    sc.intersection(nums1,nums2);
    return 0;
}