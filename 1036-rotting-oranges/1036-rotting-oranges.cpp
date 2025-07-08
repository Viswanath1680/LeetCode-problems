// Gather all the rotten oranges first
// Apply bfs in all the 4 directions

using pi = pair<int, int>;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pi> q;
        int m = grid.size(), n = grid[0].size();
        // unordered_set<pi> visited;   // apparently can't use it
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int freshOranges = 0;
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                int val = grid[i][j];
                if( val == 2 ){
                    visited[i][j] = true;
                    q.push( {i, j} );
                }
                else if( val == 1 ) freshOranges++;
            }
        }
        vector<pi> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int minutes = 0;
        while( q.size() ){
            bool infected = false;
            int size = q.size();
            while( size-- ){
                auto [r, c] = q.front(); q.pop();
                for( auto [dr, dc] : directions ){
                    int new_r = r + dr, new_c = c + dc;
                    if( new_r < 0 || new_r >= m || new_c < 0 || new_c >= n )
                        continue;
                    // now both new_c and new_r are valid indices
                    if ( !visited[new_r][new_c] ){
                        visited[new_r][new_c] = true;
                        if( grid[new_r][new_c] == 1 ){
                            infected = true;
                            q.push( {new_r, new_c} );
                            freshOranges--;
                        }
                    }
                }
            }
            if( infected )  minutes++;
        }
        if( freshOranges )  return -1;
        return minutes;
    }
};