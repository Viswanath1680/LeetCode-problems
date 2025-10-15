class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        for( int i = 0; i < nums.size(); i++ ){
            if( mp.count(nums[i]) ){
                int j = mp[nums[i]];
                if( i - j <= k )    return true;
                mp[ nums[i] ] = i;
            }
            else    mp[nums[i]] = i;
        }
        return false;
    }
};