class Solution {
public:
    // Sliding window approach
    long long countSubarrays(vector<int>& arr, long long k) {
        int n = arr.size();
        int l = 0, r = 0;
        long long curr_sum = 0, curr_len = 0;
        long long ans = 0;
        while( r < n ){
            curr_sum += arr[r];
            curr_len++;
            while( curr_sum * curr_len >= k ){
                // shrink
                curr_len--;
                curr_sum -= arr[l];
                l++;
            }
            ans += curr_len;
            r++;    
        }
        return ans;
    }
};