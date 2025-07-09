// Surrounded Regions question idea.
class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> isConnectedToEdge(m, vector<bool>(n, false));

        auto dfs = [&](auto& self, int i, int j){
            if( i < 0 || i >= m || j < 0 || j >= n )    return;
            if( board[i][j] == 0 )    return;
            if( isConnectedToEdge[i][j] )   return;
            isConnectedToEdge[i][j] = true;
            self(self, i+1, j);
            self(self, i-1, j);
            self(self, i, j+1);
            self(self, i, j-1);
        };

        for( int i = 0; i < m; i++ )    {
            if( board[i][0] == 1 )    dfs(dfs, i, 0);
            if( board[i][n-1] == 1 )  dfs(dfs, i, n-1);
        }
        // for( int i = 0; i < m; i++ )    if( board[i][n-1] == 1 )  dfs(dfs, i, n-1);
        for( int j = 0; j < n; j++ )    {
            if( board[0][j] == 1 )    dfs(dfs, 0, j);
            if( board[m-1][j] == 1 )  dfs(dfs, m-1, j);
        }
        // for( int j = 0; j < n; j++ )    if( board[m-1][j] == 1 )  dfs(dfs, m-1, j);

        int enclavesCount = 0;
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if( board[i][j] == 1 ){
                    if( !isConnectedToEdge[i][j] )   enclavesCount++;
                }
            }
        }
        return enclavesCount;
    }
};