// Neetcode https://www.youtube.com/watch?v=O-aXzrDB49w

class Solution {
    vector<vector<int>> dp;

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        dp.assign(n, vector<int>(2, -1));

        int maxLen = 1, startIndex = 0;
        for (int i = 0; i < n; i++) {
            if (dfs(i, nums) > maxLen) {
                maxLen = dp[i][0];
                startIndex = i;
            }
        }

        vector<int> subset;
        while (startIndex != -1) {
            subset.push_back(nums[startIndex]);
            startIndex = dp[startIndex][1];
        }
        return subset;
    }

private:
    int dfs(int i, vector<int>& nums) {
        if (dp[i][0] != -1) return dp[i][0];

        dp[i][0] = 1;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] % nums[i] == 0) {
                int length = dfs(j, nums) + 1;
                if (length > dp[i][0]) {
                    dp[i][0] = length;
                    dp[i][1] = j;
                }
            }
        }
        return dp[i][0];
    }
};