// BFS way
using pi = pair<int, int>;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto copy = grid;
        queue<pi> q;
        auto bfs = [&](int i, int j) -> void{
            copy[i][j] = '0';
            q.push( {i, j} );
            vector<pi> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
            while( q.size() ){
                int size = q.size();
                while( size-- ){
                    auto [r, c] = q.front(); q.pop();
                    for( auto [dr, dc] : directions ){
                        int new_r = r + dr, new_c = c + dc;
                        if( new_r < 0 || new_r >= m || new_c < 0 || new_c >= n )    continue;
                        if( copy[new_r][new_c] == '1' ){
                            q.push( {new_r, new_c} );
                            copy[new_r][new_c] = '0';
                        }
                    }
                }
            }
        };


        int islandCount = 0;
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if( copy[i][j] == '1' ){
                    islandCount++;
                    bfs(i, j);
                }
            }
        }
        return islandCount;
    }
};