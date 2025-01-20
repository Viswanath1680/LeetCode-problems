class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string b = s;
        reverse( b.begin(), b.end() );
        vector<vector<int>>M( n+1, vector<int>(n+1, 0) );
        for( int i = 1; i <= n; i++ ){
            for( int j = 1; j <= n; j++ ){
                if( s[i-1] == b[j-1] )  M[i][j] = 1 + M[i-1][j-1];
                else    M[i][j] = max( M[i-1][j], M[i][j-1] );
            }
        }
        return M[n][n];
    }
};