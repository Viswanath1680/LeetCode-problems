class Solution {
public:
    bool are9BoardsValid(vector<vector<char>>& board){
        int n = 9;
        vector<unordered_set<char>> miniboard(n);
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < 9; j++ ){
                auto c = board[i][j];
                if( c == '.' )    continue;
                int ind = 3 * ( i/3 ) + (j/3);
                if( miniboard[ind].find( c ) != miniboard[ind].end() )   return false;
                miniboard[ind].insert(c);
            }
        }
        return true;
    }

    bool areRowsAndColsValid( vector<vector<char>>& board ){
        int n = 9;
        for( int i = 0; i < n; i++ ){
            unordered_set<int> s;
            for( int j = 0; j < n; j++ ){
                char c = board[i][j];
                if( c == '.' )    continue;
                if( s.find( c ) != s.end() )    return false;
                s.insert(c);
            }
        }

        for( int i = 0; i < n; i++ ){
            unordered_set<int> s;
            for( int j = 0; j < n; j++ ){
                char c = board[j][i];
                if( c == '.' )    continue;
                if( s.find( c ) != s.end() )    return false;
                s.insert(c);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return (are9BoardsValid(board) && areRowsAndColsValid(board));   
    }
};