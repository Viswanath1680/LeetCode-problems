// Start from edges. If you find any 'O', apply dfs and store all the 'O's found from this edge 'O'. They should be remained as 'O'.
// Make remaning 'O's as 'X'
using pi = pair<int, int>;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> isConnectedToEdge(m, vector<bool>(n, false));

        vector<pi> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto bfs = [&](int i, int j) -> void{
            if( i < 0 || i >= m || j < 0 || j >= n )    return;
            if( board[i][j] == 'X' )    return;
            if( isConnectedToEdge[i][j] )   return;
            queue<pi> q;
            q.push( {i, j} );
            isConnectedToEdge[i][j] = true;
            while( !q.empty() ){
                auto [r, c] = q.front(); q.pop();
                for( auto [dr, dc] : directions ){
                    int new_r = r + dr, new_c = c + dc;
                    if( new_r < 0 || new_r >= m || new_c < 0 || new_c >= n ) continue;
                    if( board[new_r][new_c] == 'X' )    continue;
                    if( isConnectedToEdge[new_r][new_c] )   continue;
                    isConnectedToEdge[new_r][new_c] = true;
                    q.push( {new_r, new_c} );
                }
            }
        };

        for( int i = 0; i < m; i++ )    {
            if( board[i][0] == 'O' )    bfs(i, 0);
            if( board[i][n-1] == 'O' )  bfs(i, n-1);
        }
        for( int j = 0; j < n; j++ )    {
            if( board[0][j] == 'O' )    bfs(0, j);
            if( board[m-1][j] == 'O' )  bfs(m-1, j);
        }
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if( board[i][j] == 'X' )    continue;
                if( !isConnectedToEdge[i][j] )   board[i][j] = 'X';
            }
        }
    }
};