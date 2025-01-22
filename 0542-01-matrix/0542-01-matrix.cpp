class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if( mat[i][j] == 0 ){
                    ans[i][j] = 0;
                    q.push( {i, j} );
                }
            }
        }

        int delRow[4] = {1, -1, 0, 0};
        int delCol[4] = {0, 0, 1, -1};

        while( q.size() ){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();


            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && ans[nrow][ncol] == -1) {
                    ans[nrow][ncol] = ans[row][col] + 1;  
                    q.push({nrow, ncol});                
                }
            }
        }
        return ans;
    }
};