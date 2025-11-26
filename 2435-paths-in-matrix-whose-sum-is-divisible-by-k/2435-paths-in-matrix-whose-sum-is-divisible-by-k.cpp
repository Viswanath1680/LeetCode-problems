using vvi = vector<vector<int>>;
using vi = vector<int>;
using vll = vector<long long>;
using pi = pair<int, int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // vector<vll> dp( m, vll(n, 0) );
        vector<vector<vector<int>>> dp(m, vvi(n, vi(k, 0)));
        int sumTillNow = 0;
        for( int i = 0; i < m; i++ ){
            sumTillNow = ( sumTillNow + grid[i][0] ) % k;
            dp[i][0][ sumTillNow ] = 1;
        }
        sumTillNow = 0;
        for( int j = 0; j < n; j++ ){
            sumTillNow =( sumTillNow + grid[0][j] ) % k;
            dp[0][j][ sumTillNow ] = 1;
        }
        int mod = 1e9 + 7;
        for( int i = 1; i < m; i++ ){
            for( int j = 1; j < n; j++ ){
                for( int modsum = 0; modsum < k; modsum++ ){
                    int sum = ( modsum + grid[i][j] ) % k;
                    dp[i][j][sum] = ( dp[i][j][sum] + dp[i-1][j][modsum] ) % mod;
                    dp[i][j][sum] = ( dp[i][j][sum] + dp[i][j-1][modsum] ) % mod;
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};