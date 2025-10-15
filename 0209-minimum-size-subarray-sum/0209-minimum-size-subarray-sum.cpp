class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int n = arr.size();   
        int l = 0, r = 0, sum = 0;
        int ans = INT_MAX;
        while( r < n ){
            sum += arr[r];
            while( sum >= target ){
                ans = min(ans, ( r - l + 1 ));
                sum -= arr[l];
                l++;
            }
            r++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};