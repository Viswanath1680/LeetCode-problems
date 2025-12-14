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
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vvi dp(m, vi(n, -1));

        auto recursive = [&](auto& self, int i, int j) -> int{
            if( i < 0 || j < 0 )    return 0;
            if( dp[i][j] != -1 )    return dp[i][j];
            if( text1[i] == text2[j] ){
                dp[i][j] = 1 + self(self, i-1, j-1);
            }
            else
                dp[i][j] = max( self(self, i-1, j), self(self, i, j-1) );
            return dp[i][j];
        };

        return recursive( recursive, m-1, n-1 );
    }
};