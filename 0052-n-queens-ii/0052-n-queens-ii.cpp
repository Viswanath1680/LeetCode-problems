class Solution {
public:
    // Simplified N-Queens question
    bool isValid(vector<string>& board, int i, int j){
        // vertical
        int m = board.size();
        for( int p = 0; p < m; p++ ){
            if( p == i )    continue;
            if( board[p][j] == 'Q' )    return false;
        }

        // horizantal
        for( int p = 0; p < m; p++ ){
            if( p == j )    continue;
            if( board[i][p] == 'Q' )    return false;
        }

        // left diagonal
        int copy_i = i-1, copy_j = j-1;
        while( copy_i >= 0 && copy_j >= 0 ){
            if( board[copy_i][copy_j] == 'Q' )  return false;
            copy_i--, copy_j--;
        }
        copy_i = i+1, copy_j = j+1;
        while( copy_i < m && copy_j < m ){
            if( board[copy_i][copy_j] == 'Q' )  return false;
            copy_i++, copy_j++;
        }

        // right diagonal
        copy_i = i-1, copy_j = j+1;
        while( copy_i >= 0 && copy_j < m ){
            if( board[copy_i][copy_j] == 'Q' )  return false;
            copy_i--, copy_j++;
        }

        copy_i = i+1, copy_j = j-1;
        while( copy_i < m && copy_j >= 0 ){
            if( board[copy_i][copy_j] == 'Q' )  return false;
            copy_i++, copy_j--;
        }

        return true;
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        int ans = 0;
        auto recursive = [&](auto& self, int i) -> void{
            if( i == n ){
                ans++;
                return ;
            }

            for( int j = 0; j < n; j++ ){
                if( isValid(board, i, j) ){
                    board[i][j] = 'Q';
                    self(self, i+1);
                    board[i][j] = '.';
                }
            }
        };

        recursive(recursive, 0);
        return ans;
    }
};