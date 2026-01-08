class Solution {
public:
    int maxDotProduct(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size(), n = arr2.size();
        vector<vector<int>> dp( m+1, vector<int>(n+1, INT_MIN) );
        for( int i = 1; i <= m; i++ ){
            for( int j = 1; j <= n; j++ ){
                dp[i][j] = arr1[i-1] * arr2[j-1] + max(0, dp[i-1][j-1] );
                dp[i][j] = max( dp[i][j], max( dp[i-1][j], dp[i][j-1] ) );
            }
        }
        return dp[m][n];
    }
};