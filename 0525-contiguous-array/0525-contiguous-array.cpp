class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefixSum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int ans = 0;
        for( int i = 0; i < nums.size(); i++ ){
            prefixSum += ( nums[i] == 0 ? 1 : -1 );
            if( mp.find(prefixSum) == mp.end() )
                mp[ prefixSum ] = i;
            ans = max( ans, i - mp[prefixSum] );
        }
        return ans;
    }
};