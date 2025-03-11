class Solution {
public:
    // Striver Optimal Solution: https://www.youtube.com/watch?v=xtqN4qlgr8s
    int numberOfSubstrings(string s) {
        vector<int> last_seen(3, -1);
        int ans = 0;
        for( int i = 0; i < s.length(); i++ ){
            last_seen[ s[i] - 'a' ] = i;
            if( last_seen[0] != -1 && last_seen[1] != -1 && last_seen[2] != -1 ){
                ans += 1 + *min_element(last_seen.begin(), last_seen.end());
            }
        }
        return ans;
    }
};