class Solution {
public:
    int longestNiceSubarray(vector<int>& arr) {
        int ans = 1, n = arr.size();
        int l = 0, r = 0;
        int currentState = 0;  
        while (r < n) {
            while ((currentState & arr[r]) != 0) {
                currentState ^= arr[l];
                l++;
            }
            currentState |= arr[r];
            r++;
            ans = max(ans, r - l);
        }
        return ans;
    }
};
