class Solution {
public:
    int numSubseq(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int ans = 0, MOD = 1e9 + 7;
        int left = 0, right = n-1;
        int i = 0;
        vector<int> powers(n, 1);
        for( i = 1; i < n; i++ )    powers[i] = ( 2 * powers[i-1] ) % MOD;
        while( left <= right ){
            if( arr[left] + arr[right] <= target ){
                ans = ( ans % MOD + powers[right-left] % MOD ) % MOD;
                left++;
            }
            else    right--;
        }
        return ans;
    }
};