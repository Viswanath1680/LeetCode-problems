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
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        if( n == 3 )    return ( values[0] * values[1] * values[2] );

        vvi dp(n, vi(n, -1));
        for( int i = 0; i < n; i++ ){
            dp[i][i] = 0;
            if( i != n-1 )  dp[i][i+1] = 0;
        }

        auto recursive = [&](auto& self, int i, int j) -> int{
            if( dp[i][j] != -1 )    return dp[i][j];
            if( j - i + 1 == 3 ){
                dp[i][j] = values[i] * values[i+1] * values[i+2];
                return dp[i][j];
            }
            int val = INT_MAX;
            for( int k = i+1; k < j; k++ )
                val = min(val,  values[i] * values[k] * values[j] + self(self, i, k) + self(self, k, j) );
            dp[i][j] = val;
            return dp[i][j];
        };

        return recursive(recursive, 0, n-1);
    }
};