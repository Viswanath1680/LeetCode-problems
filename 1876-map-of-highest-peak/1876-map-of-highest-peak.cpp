class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        if( i < 0 || i >=m || j < 0 || j >= n)  return false;
        return true;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if( mat[i][j] == 1 ){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int row[4] = {1, -1, 0, 0};
        int col[4] = {0, 0, 1, -1};
        while( q.size() ){
            int x = q.front().first, y = q.front().second;
            for( int i = 0; i < 4; i++ ){
                int a = x + row[i], b = y + col[i];
                if( isValid(a, b, m, n) && ans[a][b] == -1 ){
                    ans[a][b] = 1 + ans[x][y];
                    q.push({a, b});
                }
            }
            q.pop();
        }
        return ans;
    }
};