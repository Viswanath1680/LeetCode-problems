class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = 0, n = nums.size();
        for( auto it : nums )   sum += it;
        long long actual = (long long) n*(n+1)/2;
        return actual - sum;
    }
};