using vvi = vector<vector<int>>;
using vi = vector<int>;
using pi = pair<int, int>;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<pi> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        auto isPossible = [&](auto& self, int day) -> bool{
            vvi grid(row, vi(col, 0));
            for( int i = 0; i < day; i++ ){
                int r = cells[i][0]-1, c = cells[i][1] - 1;
                grid[r][c] = 1;
            }
            queue<pi> q;
            for( int i = 0; i < col; i++ ){
                if( grid[0][i] == 0 )   {
                    q.push( {0, i} );
                    grid[0][i] = -1;    // visited
                }
            }
            while( !q.empty() ){
                auto [r, c] = q.front();    q.pop();
                if( r == row-1 )    return true;
                for( auto& [dr, dc] : directions ){
                    int nr = r + dr, nc = c + dc;
                    if( nr < 0 || nr >= row || nc < 0 || nc >= col )    continue;
                    if( grid[nr][nc] != 0 ) continue;
                    grid[nr][nc] = -1;
                    q.push( {nr, nc} );
                }
            }
            return false;
        };

        // binary search on ans
        int low = 1, high = cells.size();
        int ans;
        while( low <= high ){
            int mid = low + ( high - low )/2;
            auto val = isPossible(isPossible, mid);
            if( val ){
                ans = mid;
                low = mid + 1;
            }
            else    high = mid - 1;
        }
        return ans;
    }
};