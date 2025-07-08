using pi = pair<int, int>;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if( image[sr][sc] == color )    return image;
        int m = image.size(), n = image[0].size();
        vector<vector<int>> ans = image;
        int initial_color = image[sr][sc];
        ans[sr][sc] = color;
        queue<pi> q;
        q.push( {sr, sc} );
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[sr][sc] = true;
        vector<pi> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while( q.size() ){
            int size = q.size();
            while( size-- ){
                auto [r, c] = q.front(); q.pop();
                for( auto [dr, dc] : directions ){
                    int new_r = r + dr, new_c = c + dc;
                    if( new_r < 0 || new_r >= m || new_c < 0 || new_c >= n )    continue;
                    if( !visited[new_r][new_c] ){
                        visited[new_r][new_c] = true;
                        if( ans[new_r][new_c] == initial_color ){
                            ans[new_r][new_c] = color;
                            q.push( {new_r, new_c} );
                        }
                    }
                }
            }
        }
        return ans;
    }
};