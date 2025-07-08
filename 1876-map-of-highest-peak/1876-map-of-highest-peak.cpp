// Similar to Rotten Oranges question
// Push all the zeroes to the queue

using pi = pair<int, int>;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pi> q;
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if( mat[i][j] == 0 )    continue;
                q.push( {i, j} );
                visited[i][j] = true;
            }
        }
        int minutes = 1;    // rotten Oranges reference
        vector<pi> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while( q.size() ){
            int size = q.size();
            bool isInfected = false;
            while( size-- ){
                auto [r, c] = q.front(); q.pop();
                for( auto [dr, dc] : directions ){
                    int new_r = r + dr, new_c = c + dc;
                    if( new_r < 0 || new_r >= m || new_c < 0 || new_c >= n )    continue;
                    if( !visited[new_r][new_c] ){
                        visited[new_r][new_c] = true;
                        q.push( {new_r, new_c} );
                        if( mat[new_r][new_c] == 0 ){
                            isInfected = true;
                            ans[new_r][new_c] = minutes;
                        }
                    }
                }
            }
            if( isInfected )    minutes++;
        }
        return ans;
    }
};