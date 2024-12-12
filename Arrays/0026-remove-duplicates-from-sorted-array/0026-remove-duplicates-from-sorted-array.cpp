class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for( auto it : nums )    mp[it] = it;
        nums.clear();
        for( auto it : mp ) nums.emplace_back(it.first);
        return mp.size();
    }
};