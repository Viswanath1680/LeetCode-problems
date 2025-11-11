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


// Just trying the back tracking way. I know it's TLE
// Adding dp to it
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ans = 0;
        vector<vector<vector<int>>> dp(strs.size(), vvi(m+1, vi(n+1, -1)));
        auto backtrack = [&](auto& self, int i, int m, int n) -> int{
            if( i == strs.size() )    return 0;
            if( dp[i][m][n] != -1 ) return dp[i][m][n];
            dp[i][m][n] = self( self, i+1, m, n);
            int zeroes_count = 0, ones_count = 0;
            for( auto& c : strs[i] ){
                if( c == '0' )  zeroes_count++;
                else    ones_count++;
            }
            if( zeroes_count <= m && ones_count <= n ){
                dp[i][m][n] = max(dp[i][m][n],
                self(self, i+1, m-zeroes_count, n-ones_count) + 1 );
            }
            return dp[i][m][n];
        };

        return backtrack(backtrack, 0, m, n);
    }
};