// Add 4 for every land cell.
// Subtract 1 for each direct neighbor that is also land (up, down, left, right).

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int nRow = grid.size(), nCol = grid[0].size();
        int perimeter = 0;
        for (int r = 0; r < nRow; r++) {
            for (int c = 0; c < nCol; c++) {
                if( grid[r][c] == 0 )   continue;
                
                perimeter += 4;
                if (c - 1 >= 0 && grid[r][c - 1] == 1)    perimeter -= 1;
                if (c + 1 < nCol && grid[r][c + 1] == 1)    perimeter -= 1;
                if (r - 1 >= 0 && grid[r - 1][c] == 1)    perimeter -= 1;
                if (r + 1 < nRow && grid[r + 1][c] == 1)    perimeter -= 1;
            }
        }

        return perimeter;
    }
};