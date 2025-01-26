class Solution {
public:
// 2d dp suppose x and y parity unna alternating subsequence kavali manaki. 
// dp[i][x] -> i ante index, x ante kavalsina parity 
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        for( int i = 0 ; i < n ; i++)   nums[i] = nums[i] % k;
        vector<vector<int>>dp(n, vector<int>(k,0));
        vector<int> last_seen(k,-1); // last_seen[i] ante 'i' parity ni chusina highest index
        int ans = 0;
        for( int i = 0 ; i < n ; i++){
            for( int parity = 0 ; parity < k; parity++){
                if( last_seen[parity] == -1 )   dp[i][parity] = 1;
                else    dp[i][parity] = 1 + dp[ last_seen[parity] ][nums[i]];
                ans = max( ans, dp[i][parity] );
            }
            last_seen[nums[i]] = i;
        }
        // for( int i = 0 ; i < k; i++)
        //     ans = max( dp[n-1][i], ans );
        return ans;
    }
};