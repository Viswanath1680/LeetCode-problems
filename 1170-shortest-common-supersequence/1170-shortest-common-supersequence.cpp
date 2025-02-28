class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        if( m == 0 || n == 0 )
            return ( str1 + str2 );
        vector<vector<int>>M(n+1, vector<int>(m+1, 0) );
        for( int i = 1; i <= n ; i++){
            for( int j = 1; j <= m ; j++){
                if( str1[i-1] == str2[j-1] )
                    M[i][j] = 1 + M[i-1][j-1];
                else
                    M[i][j] = max( M[i-1][j], M[i][j-1] );
            }
        }
        string ans = "";
        int i = n, j = m;
        while( i && j ){
            if( str1[i-1] == str2[j-1] ){
                ans += str1[i-1];
                i--, j--;
            }
            else{
                if( M[i-1][j] > M[i][j-1] ){
                    ans += str1[i-1];
                    i--;
                }
                else{
                    ans += str2[j-1];
                    j--;
                }
            }
        }
        while( i )
            ans += str1[--i];
        while( j )
            ans += str2[--j];
        reverse( ans.begin(), ans.end() );
        return ans;
    } 
};