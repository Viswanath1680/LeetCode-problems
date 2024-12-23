class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        vector<bool>dp(n, false);
        dp[0] = true;
        for( int i = 0; i < n; i++ ){
            int j;
            for( int k = 1; k <= arr[i]; k++ ){
                j = i + k;
                if( j < n ) dp[j] = dp[j] || ( dp[i] && true ); 
            }
        }
        return dp[n-1];
    }
};