class Solution {
public:
    bool isValid( int m, int n, int x, int y ){
        return ( x >= 0 && y >= 0 ) && ( x < m && y < n );
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int m, int n, int x, int y){
        vector<int> row = {0, 0, -1, 1};
        vector<int> col = {-1, 1, 0, 0};
        int count = grid[x][y];
        for( int p = 0; p < 4; p++ ){
            int newx = x + row[p];
            int newy = y + col[p];
            if( isValid(m, n, newx, newy) && !isVisited[newx][newy] && grid[newx][newy] ) { 
                isVisited[newx][newy] = true;
                count += dfs(grid, isVisited, m, n, newx, newy);
            }
            // else    return 0;
        }
        return count;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if( grid[i][j] && !isVisited[i][j] ){
                    isVisited[i][j] = true;
                    ans = max(ans, dfs(grid, isVisited, m, n, i, j));
                }
            }
        }
        return ans;
    }
};