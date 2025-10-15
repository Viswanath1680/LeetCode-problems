class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for( int i = 0; i < nums.size(); i++ ){
            if( ump.count(nums[i]) ){
                int j = ump[nums[i]];
                if( i - j <= k )    return true;
                ump[ nums[i] ] = i;
            }
            else    ump[nums[i]] = i;
        }
        return false;
    }
};