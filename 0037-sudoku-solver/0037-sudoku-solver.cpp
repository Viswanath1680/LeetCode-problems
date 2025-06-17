class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = 9;
        vector<vector<int>> sudoku(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    sudoku[i][j] = 0;
                } else {
                    sudoku[i][j] = board[i][j] - '0';
                }
            }
        }
        vector<unordered_set<int>> miniboard(n);
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < n; j++ ){
                auto c = sudoku[i][j];
                if( c == 0 )    continue;
                int ind = 3 * ( i/3 ) + (j/3);
                miniboard[ind].insert(c);
            }
        }
        vector<unordered_set<int>> rows(n);
        vector<unordered_set<int>> columns(n);
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < n; j++ ){
                auto c = sudoku[i][j];
                if( c == 0 ) continue;
                rows[i].insert(c);
                columns[j].insert(c);
            }
        }

        auto recursive = [&](auto& self, int i, int j) -> bool{
            if( j == n ){
                i++;
                j = 0;
            }
            if( i == n )    return true;
            if( sudoku[i][j] != 0 ) return self(self, i, j+1);

            int ind = 3 * (i/3) + (j/3);
            for( int k = 1; k <= n; k++ ){
                bool condn = ( rows[i].find(k) == rows[i].end() ) && ( columns[j].find(k) == columns[j].end() ) && ( miniboard[ind].find(k) == miniboard[ind].end() );

                if( condn == false )    continue;
                sudoku[i][j] = k;
                rows[i].insert(k);
                columns[j].insert(k);
                miniboard[ind].insert(k);

                if (self(self, i, j + 1)) return true;

                sudoku[i][j] = 0;
                rows[i].erase(k);
                columns[j].erase(k);
                miniboard[ind].erase(k);
            }
            return false;
        };

        recursive(recursive, 0, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = (char) (sudoku[i][j] + '0');
            }
        }
        return;
    }
};