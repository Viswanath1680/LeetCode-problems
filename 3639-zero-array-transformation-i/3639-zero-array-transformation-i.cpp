class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>prefix(n+1, 0);
        for( auto query : queries ){
            int l = query[0], r = query[1];
            prefix[l]++;
            prefix[r+1]--;
        }
        if( nums[0] > prefix[0] )   return false;
        for( int i = 1; i < n; i++ )   {
            prefix[i] += prefix[i-1];
            if( nums[i] > prefix[i] )   return false;
        }
        return true;
    }
};