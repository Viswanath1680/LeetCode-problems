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
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        if( m < n ) return 0;
        if( m == n ){
            if( s == t ) return 1;
            return 0;
        }

        vvi memo(m, vector<int>(n, -1));

        auto recursive = [&](auto& self, int i, int j ) -> int{
            if( j == n ){
                return 1;
            }
            if( i == m )    return 0;

            if( memo[i][j] != -1 ) return memo[i][j];

            int count = 0;
            if( s[i] == t[j] ){
                count += self(self, i+1, j+1 );
            }
            count += self( self, i+1, j );

            return memo[i][j] = count;
        };

        return recursive( recursive, 0, 0 );
    }
};