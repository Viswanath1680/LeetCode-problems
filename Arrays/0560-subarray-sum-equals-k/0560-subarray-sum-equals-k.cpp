class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long, int> ump;
        long long sum = 0;
        int ans = 0;
        for( int i = 0; i < n; i++){
            sum += nums[i];
            int target = sum - k;
            if( ump.find( target ) != ump.end() )
                ans += ump[ target ];
            if( sum == k )  ans++;
            ump[sum]++;
        }
        return ans;
    }
};