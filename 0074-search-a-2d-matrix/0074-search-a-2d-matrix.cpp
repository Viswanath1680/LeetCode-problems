class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, h = m-1, mid;
        int lowerbound = 0;
        while( l <= h ){
            mid = l + (h-l)/2;
            if( matrix[mid][0] == target )  return true;
            if( matrix[mid][0] >= target )   h = mid - 1;
            else    {
                lowerbound = mid;
                l = mid + 1;
            }
        }
        cout << lowerbound;
        return binary_search( matrix[lowerbound].begin(), matrix[lowerbound].end(), target );
    }
};