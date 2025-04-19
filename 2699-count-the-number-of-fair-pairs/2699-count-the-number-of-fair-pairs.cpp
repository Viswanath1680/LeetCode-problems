class Solution {
public:
    // Simple Binary search
    long long countFairPairs(vector<int>& arr, int lower, int upper) {
        long long ans = 0;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for( int i = 0; i < n; i++ ){
            int lowerTarget = lower - arr[i];
            int upperTarget = upper - arr[i];
            int lowerInd = lower_bound(arr.begin()+i+1, arr.end(), lowerTarget) - arr.begin();
            int upperInd = upper_bound(arr.begin()+i+1, arr.end(), upperTarget) - arr.begin();
            ans += (long long)( upperInd - lowerInd );
        }
        return ans;
    }
};