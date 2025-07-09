// start from edges. If you find any 'O', apply bfs and store all the 'O's found from this edge 'O'. They should be remained as 'O'.
// Make remaning 'O's as 'X
using pi = pair<int, int>;

struct hash_pair {
    size_t operator()(const pi& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        unordered_map<pi, bool, hash_pair> isConnectedToEdge;

        auto dfs = [&](auto& self, int i, int j){
            if( i < 0 || i >= m || j < 0 || j >= n )    return;
            if( board[i][j] == 'X' )    return;
            if( isConnectedToEdge.find( {i, j} ) != isConnectedToEdge.end() )   return;
            isConnectedToEdge[ {i, j} ] = true;
            self(self, i+1, j);
            self(self, i-1, j);
            self(self, i, j+1);
            self(self, i, j-1);
        };

        for( int i = 0; i < m; i++ )    {
            if( board[i][0] == 'O' )    dfs(dfs, i, 0);
            if( board[i][n-1] == 'O' )  dfs(dfs, i, n-1);
        }
        // for( int i = 0; i < m; i++ )    if( board[i][n-1] == 'O' )  dfs(dfs, i, n-1);
        for( int j = 0; j < n; j++ )    {
            if( board[0][j] == 'O' )    dfs(dfs, 0, j);
            if( board[m-1][j] == 'O' )  dfs(dfs, m-1, j);
        }
        // for( int j = 0; j < n; j++ )    if( board[m-1][j] == 'O' )  dfs(dfs, m-1, j);

        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if( board[i][j] == 'O' ){
                    if( isConnectedToEdge.find( {i, j} ) == isConnectedToEdge.end() )   board[i][j] = 'X';
                }
            }
        }
    }
};