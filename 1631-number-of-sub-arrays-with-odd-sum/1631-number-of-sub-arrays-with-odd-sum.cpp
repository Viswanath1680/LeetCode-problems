class Solution {
public:
    // Same as Subarray-Sum-equals-K question. https://leetcode.com/problems/subarray-sum-equals-k/
    int numOfSubarrays(vector<int>& arr) {
        for(auto& it: arr)  it = it & 1;
        vector<int>count(2, 0);
        long long ans = 0;
        int prefix_sum = 0;
        for(int i = 0; i < arr.size(); i++){
            prefix_sum = ( prefix_sum % 2 + arr[i] %2 ) % 2;
            int target = abs(prefix_sum - 1);
            ans += count[target];
            if( prefix_sum == 1 )   ans++;
            count[prefix_sum]++;
        }
        int MOD = 1e9 + 7;
        return ans % MOD;
    }
};