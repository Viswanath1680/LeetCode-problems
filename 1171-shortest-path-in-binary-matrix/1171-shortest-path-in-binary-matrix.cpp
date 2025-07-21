// Apply BFS while going through all the valid nodes and return the first encounter
using pi = pair<int, int>;
using pipi = pair<int, pair<int,int>>;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pipi> q;
        q.push( {1, {0, 0}} );
        visited[0][0] = true;
        vector<pi> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
        while( !q.empty() ){
            auto [dist, rc] = q.front(); q.pop();
            auto [r, c] = rc;
            if( r == n-1 && c == n-1 )  return dist;
            for( auto [dr, dc] : directions ){
                auto new_r = r + dr, new_c = c + dc;
                if( new_r < 0 || new_r >= n || new_c < 0 || new_c >= n )    continue;
                if( visited[new_r][new_c] ) continue;
                if( grid[new_r][new_c] == 1 )   continue;
                visited[new_r][new_c] = true;
                // if( new_r == n-1 && new_c == n-1 )  return (dist+1);
                q.push( {dist+1, {new_r, new_c}} );
            }
        }
        return -1;
    }
};