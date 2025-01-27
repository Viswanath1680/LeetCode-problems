class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 )    return nums[0];
        if( n == 2 )    return max( nums[0], nums[1] );
        vector<int> cache(n,0);
        cache[0] = nums[0];
        cache[1] = max( nums[0], nums[1] );
        for( int i = 2; i < n ; i++){
            cache[i] = max( cache[i-1], cache[i-2] + nums[i] );
        }
        return cache[n-1];
    }
};