class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.length();
        
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        
        return recursive(s, 0, n - 1, k, memo);
    }
    
private:
    int recursive(const string& s, int i, int j, int k, vector<vector<vector<int>>>& memo) {
        if (i > j) return 0;
        if (i == j) return 1;
        
        if (memo[i][j][k] != -1) {
            return memo[i][j][k];
        }
        // skip current i
        int result = recursive(s, i + 1, j, k, memo);

        // skip current j        
        result = max(result, recursive(s, i, j - 1, k, memo));
        
        // try making them equal. result is the max of all these possibilites.
        if (s[i] == s[j]) {
            result = max(result, 2 + recursive(s, i + 1, j - 1, k, memo));
        } else if (k > 0) {
            for (char target = 'a'; target <= 'z'; target++) {
                int ops_i = minOps(s[i], target);
                int ops_j = minOps(s[j], target);
                int total_ops = ops_i + ops_j;
                
                if (total_ops <= k) {
                    result = max(result, 2 + recursive(s, i + 1, j - 1, k - total_ops, memo));
                }
            }
        }
        
        memo[i][j][k] = result;
        return result;
    }
    
    int minOps(char c1, char c2) {
        int dist = abs(c1 - c2);
        return min(dist, 26 - dist);
    }
};