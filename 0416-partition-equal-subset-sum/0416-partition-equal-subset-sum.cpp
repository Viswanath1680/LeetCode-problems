class Solution {
public:
    // knapsack problem
    // Identify a subset such that it's sum = (sum of array)/2
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for( auto it : nums )    sum += it;
        if( sum & 1 )    return false;
        int target = sum/2;
        int n = nums.size();
        vector<vector<bool>> M( n+1, vector<bool>(target+1, false) );
        for( int i = 0 ; i <= n; i++ )    M[i][0] = true;
        for( int i = 1; i <= n ; i++)
            for( int j = 1; j <= target; j++){
                // either take the value or leave it
                if( nums[i-1] <= j )    M[i][j] = M[i-1][j-nums[i-1]] || M[i-1][j];
                // since nums[i-1] > j, skip the value
                else    M[i][j] = M[i-1][j];
            }
        return M[n][target];
    }
};