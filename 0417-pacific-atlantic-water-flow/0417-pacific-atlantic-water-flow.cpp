// Quoting Jacobi(Neetcode yt short https://youtube.com/shorts/4JAUsDqiV70?si=JLz2DcQ0QaAC6-I7), "Invert, always invert"
using pi = pair<int, int>;
class Solution {
public:
    vector<vector<int>> getIntersection(const set<pi>& pacific, const set<pi>& atlantic) {
        vector<vector<int>> result;
        for (const auto& point : pacific) {
            if (atlantic.count(point)) {
                result.push_back({point.first, point.second});
            }
        }
        return result;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<pi> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        
        auto dfs = [&](auto& self, set<pi>& s, int r, int c) -> void{
            if( s.find( {r, c} ) != s.end() )   return;
            s.insert( {r, c} );
            for( auto [dr, dc] : directions ){
                auto nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (heights[nr][nc] < heights[r][c]) continue;
                self(self, s, nr, nc);
            }
        };

        set<pi> pacific, atlantic;
        // cover pacific -> left, top
        for( int i = 0; i < n; i++ )    dfs(dfs, pacific, 0, i); // top
        for( int i = 0; i < m; i++ )    dfs(dfs, pacific, i, 0); // left

        // cover atlantic -> right, down
        for( int i = 0; i < n; i++ )    dfs(dfs, atlantic, m-1, i);
        for( int i = 0; i < m; i++ )    dfs(dfs, atlantic, i, n-1);

        return getIntersection(pacific, atlantic);
    }
};