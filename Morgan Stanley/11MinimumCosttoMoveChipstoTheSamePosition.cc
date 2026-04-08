#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd=0,even=0;
        for(auto pos:position){
            if(pos%2!=0){
                odd++;
            }
            else{
                even++;
            }
        }
        return min(odd,even);
    }
};