// DFS seems more intuitive

using pi = pair<int, int>;
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pi> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        auto dfs = [&](auto& self, int i, int j, int parent_i, int parent_j, char originalChar) -> bool {
            visited[i][j] = true;
            for (auto [dr, dc] : directions) {
                int ni = i + dr, nj = j + dc;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (grid[ni][nj] != originalChar) continue;
                if (!visited[ni][nj]) {
                    if (self(self, ni, nj, i, j, originalChar)) return true;
                } else if (ni != parent_i || nj != parent_j)    return true;
            }
            return false;
        };

        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if( visited[i][j] ) continue;
                if( dfs(dfs, i, j, -1, -1, grid[i][j]) )    return true;
            }
        }
        return false;
    }
};