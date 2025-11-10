using vvi = vector<vector<int>>;
using vi = vector<int>;
using vll = vector<long long>;
using pi = pair<int, int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;
using ll = long long;
using ull = unsigned long long;

// Using DSU. Assign each connected component to a parent.
// Now traverse the grid. For every zero, check its neighbors and add the maximum size of two different connected components size
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vvi parent( m, vi(n, -1) );
        vvb visited(m, vb(n, false));
        unordered_map<int, int> size;
        vector<pi> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        
        auto bfs = [&]( auto& self, int i, int j, int parentNum) -> void{
            queue<pi> q;
            q.push( {i, j} );
            while( !q.empty() ){
                auto [r, c] = q.front(); q.pop();
                if( visited[r][c] ) continue;
                visited[r][c] = true;
                parent[r][c] = parentNum;
                size[parentNum]++;
                for( auto& [dr, dc] : directions ){
                    int nr = r + dr, nc = c + dc;
                    if( nr < 0 || nr >= m || nc < 0 || nc >= n )    continue;
                    if( visited[nr][nc] || grid[nr][nc] == 0 )   continue;
                    q.push( {nr, nc} );
                }
            }
        };

        int parentNum = 1;
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if( grid[i][j] == 0 )   continue;
                if( visited[i][j] ) continue;
                bfs(bfs, i, j, parentNum);
                parentNum++;
            }
        }
        // all connected components are assigned a parentNum.
        int ans = 0;
        for( auto& [parent, s] : size )  {
            ans = max(ans, s);
            cout << parent << " " << s << "\n";
        }
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if( grid[i][j] == 1 )   continue;
                unordered_set<int> s;
                int temp_ans = 1;
                for( auto [dr, dc] : directions ){
                    int nr = i + dr, nc = j + dc;
                    if( nr < 0 || nr >= m || nc < 0 || nc >= n )    continue;
                    if( grid[nr][nc] == 0 ) continue;
                    int parentNumber = parent[nr][nc];
                    if( s.count( parentNumber ) )  continue;
                    s.insert( parentNumber );
                    temp_ans += size[parentNumber];
                }
                ans = max(ans, temp_ans);
            }
        }
        return ans;
    }
};