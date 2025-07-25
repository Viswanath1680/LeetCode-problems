// Quoting Jacobi(Neetcode yt short https://youtube.com/shorts/4JAUsDqiV70?si=JLz2DcQ0QaAC6-I7), "Invert, always invert"
using pi = pair<int, int>;
using vvb = vector<vector<bool>>;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<pi> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        
        auto dfs = [&](auto& self, vvb& visited, int r, int c) -> void{
            if (visited[r][c]) return;
            visited[r][c] = true;
            for( auto [dr, dc] : directions ){
                auto nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (heights[nr][nc] < heights[r][c]) continue;
                self(self, visited, nr, nc);
            }
        };

        vvb pacific(m, vector<bool>(n, false));
        vvb atlantic(m, vector<bool>(n, false));
        // cover pacific -> left, top
        for( int i = 0; i < n; i++ )    dfs(dfs, pacific, 0, i); // top
        for( int i = 0; i < m; i++ )    dfs(dfs, pacific, i, 0); // left

        // cover atlantic -> right, down
        for( int i = 0; i < n; i++ )    dfs(dfs, atlantic, m-1, i);
        for( int i = 0; i < m; i++ )    dfs(dfs, atlantic, i, n-1);

        vector<vector<int>> result;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pacific[r][c] && atlantic[r][c])
                    result.push_back({r, c});
            }
        }
        return result;
    }
};