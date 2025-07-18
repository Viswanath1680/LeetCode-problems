// create a graph as follows
// if richer[i] = [0, 1] -> edge 0 - 1
// now answer[0] = apply dfs on 0. Min of all nodes found
// Applying kahn's algo is not useful.
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        for (auto& r : richer)    graph[r[1]].push_back(r[0]);

        vector<int> answer(n);
        vector<bool> visited(n, false);

        auto dfs = [&](auto& self, int node) -> int {
            if (visited[node]) return answer[node];
            visited[node] = true;
            answer[node] = node;

            for (int neighbor : graph[node]) {
                int candidate = self(self, neighbor);
                if (quiet[candidate] < quiet[answer[node]]) {
                    answer[node] = candidate;
                }
            }
            return answer[node];
        };

        for (int i = 0; i < n; ++i) {
            dfs(dfs, i);
        }
        return answer;
    }
};