class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat[0].size();
        int m = mat.size();
        unordered_map<int, vector<int>> ump;
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                int element = mat[i][j];
                ump[ element ].emplace_back(i);
                ump[ element ].emplace_back(j);
            }
        }
        vector<int>rows(m, n);
        vector<int>cols(n, m);
        int x, y;
        int mini = min(m, n);
        for( int i = 0; i < mini; i++ ){
            int element = arr[i];
            x = ump[ element ][0];
            y = ump[ element ][1];
            rows[x]--;
            cols[y]--;
        }
        if( rows[x] == 0 || cols[y] == 0 )  return mini-1;
        for( int i = mini; i < m*n; i++ ){
            int element = arr[i];
            x = ump[ element ][0];
            y = ump[ element ][1];
            rows[x]--;
            cols[y]--;
            if( rows[x] == 0 || cols[y] == 0 )  return i;
        }
        return m*n;
    }
};