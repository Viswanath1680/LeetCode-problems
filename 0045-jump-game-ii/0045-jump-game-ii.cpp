class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for( int i = 0; i < n; i++ ){
            int steps = arr[i];
            for( int step = 1; step <= steps; step++){
                int ind = i + step;
                if( ind < n )    dp[ind] = min( dp[ind], 1 + dp[i] );
            }
        }
    return dp[n-1];
}
};