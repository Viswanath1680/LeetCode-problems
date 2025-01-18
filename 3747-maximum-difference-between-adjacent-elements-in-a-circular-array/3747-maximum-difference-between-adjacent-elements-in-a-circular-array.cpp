class Solution {
public:
    int maxAdjacentDistance(vector<int>& arr) {
        int n = arr.size();
        int ans = abs(arr[0] - arr[n-1]);
        for( int i = 1; i < n; i++ ){
            ans = max(ans, abs( arr[i] - arr[i-1] ));
        }
        return ans;
    }
};