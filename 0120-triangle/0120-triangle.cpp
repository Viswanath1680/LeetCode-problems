class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int level = 2;
        for( int i = 1; i < n; i++ ){
            triangle[i][0] += triangle[i-1][0];
            triangle[i][level-1] += triangle[i-1][level-2];
            for( int j = 1; j < level - 1; j++ ){
                triangle[i][j] += min( triangle[i-1][j], triangle[i-1][j-1] );
            }
            level++;
        }
        return *min_element( triangle[n-1].begin(), triangle[n-1].end() );
    }
};