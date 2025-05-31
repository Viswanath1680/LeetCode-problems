class Solution {
public:
    pair<int, int> intToPosition(int num, int n) {
        int r = (num - 1) / n;
        int c = (num - 1) % n;
        if (r % 2 == 1) c = n - 1 - c;  // reverse column index on odd rows
        r = n - 1 - r;                 // flipping row index (because row 0 is bottom)
        return {r, c};
    }


    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();   // no of rows
        queue<pair<int, int>> q;
        q.push({1, 0});
        unordered_map<int, int> ump;
        while( q.size() ){
            auto p = q.front();
            q.pop();
            auto curr = p.first, moves = p.second;
            for( int i = 1 ; i <= 6; i++ ){
                auto next = min(curr+i, n*n);
                p = intToPosition(next, n);
                auto r = p.first, c = p.second;
                if( board[r][c] != -1 ) next = board[r][c];
                if( next == n*n )   return (moves+1);   // extra 1 move to reach next from curr
                if( ump.find( next ) == ump.end() ) {
                    ump[next] = moves+1;
                    q.push( {next, moves+1} );
                }
            }
        }
        return -1;
    }
};