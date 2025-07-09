class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto copy = grid;
        auto dfs = [&](auto& self, int i, int j) -> int{
            if( i < 0 || i >= m || j < 0 || j >= n )    return 0;
            if( copy[i][j] == 0 )   return 0;
            copy[i][j] = 0;
            int area = 1;
            area += self(self, i+1, j);
            area += self(self, i-1, j);
            area += self(self, i, j+1);
            area += self(self, i, j-1);
            return area;
        };
        int maxArea = 0;
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if( copy[i][j] == 0 )   continue;
                maxArea = max(maxArea, dfs(dfs, i, j));
            }
        }
        return maxArea;
    }
};