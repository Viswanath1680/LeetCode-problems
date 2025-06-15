class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> positions;
        int m = board.size(), n = board[0].size();
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if( board[i][j] == word[0] )    positions.push_back({i, j});
            }
        }

        auto recursive = [&](auto & self, int a, int b, int i) -> bool{
            if( i == word.size() )  return true;
            if( a < 0 || a == m || b < 0 || b == n || board[a][b] != word[i] )    return false;

            auto temp = board[a][b];
            board[a][b] = '#';

            bool b1 = self(self, a-1, b, i+1),
            b2 = self(self, a+1, b, i+1),
            b3 = self(self, a, b+1, i+1),
            b4 = self(self, a, b-1, i+1);

            board[a][b] = temp;

            return ( b1 || b2 || b3 || b4 );
        };

        for( auto v : positions ){
            int a = v[0], b = v[1];
            if( recursive(recursive, a, b, 0) )    return true;
        }
        return false;
    }
};