class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i)    adj[parent[i]].push_back(i);

        int ans = 1;
        auto dfs = [&](auto& self, int node) -> int{
            int max1 = 0, max2 = 0; 
            for (auto child : adj[node]) {
                int childPath = self(self, child);
                if ( s[child] != s[node] ) {
                    if (childPath > max1) {
                        max2 = max1;
                        max1 = childPath;
                    } 
                    else if (childPath > max2)    max2 = childPath;
                }
            }

            ans = max(ans, 1 + max1 + max2);
            return 1 + max1;
        };

        dfs(dfs, 0);
        return ans;
    }
};