class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        if( k <= 1 )    return 0;
        int n = arr.size();
        int ans = 0;
        int l = 0, r = 0;
        long long product = 1;
        while( r < n ){
            product *= arr[r];
            while( product >= k ){
                product /= arr[l];
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
};