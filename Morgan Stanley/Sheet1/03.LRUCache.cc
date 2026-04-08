 //leetcode 146...
#include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    int n;
    list<int>ddl;
    unordered_map<int,pair<list<int>::iterator,int>>mp;//{key,{address,value}}
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) { 
        if(mp.find(key)==mp.end()){//not found
            return -1;
        }
        auto del_addr=mp[key].first;
        int val=mp[key].second;
        ddl.erase(del_addr);
        ddl.push_front(key);
        mp[key].first=ddl.begin();
        return val;  
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){//found
            auto del_addr=mp[key].first;
            ddl.erase(del_addr);
            ddl.push_front(key);
            mp[key].first=ddl.begin();
            mp[key].second=value;
            return;
        }
        ddl.push_front(key);
        mp[key]={ddl.begin(),value};
        n--;
        if(n<0){
            auto del_key=ddl.back();
            ddl.pop_back();
            mp.erase(del_key);
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

