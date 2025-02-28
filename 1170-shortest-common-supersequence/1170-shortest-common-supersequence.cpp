class Solution {
public:
    // LCS logic. First get LCS of both strings. For example, consider abcd and bcfg. Their LCS is bc
    // After the LCS logic is done, add if there are any left ones in the strings.
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size(); 
        vector<vector<int>> M(m+1, vector<int>(n+1, 0));
        for( int i = 1; i <= m; i++ ){
            for( int j = 1; j <= n; j++ ){
                if( str1[i-1] == str2[j-1] )    M[i][j] = 1 + M[i-1][j-1];
                else    M[i][j] = max(M[i-1][j], M[i][j-1]);
            }
        }
        // Now backtrack(Iteratively) to get the LCS string.
        string ans = "";
        int i = m, j = n;
        while( i && j ){
            if( str1[i-1] == str2[j-1] ){
                ans += str1[i-1];
                i--, j--;
            }
            else{
                if( M[i][j-1] > M[i-1][j] ){
                    ans += str2[j-1];
                    j--;
                }
                else{
                    ans += str1[i-1];
                    i--;
                }
            }
        }
        // add the remaining to the ans string.
        while(i)    ans += str1[--i];
        while(j)    ans += str2[--j];
        reverse(ans.begin(), ans.end());
        return ans;
    }
};