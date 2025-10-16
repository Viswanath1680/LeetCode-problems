// Going with prefix and suffix sum is one way
// another genius way is to think in the reverse direction
// We need a subarray of maximum length whose sum is TotalSum - x. As we remove minimum no of elements from left and right to get a sum of x, we will be left with a subarray of maximum length having sum of TotalSum-x.

class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        int target_sum = 0; // it is TotalSum - x
        for( auto& it : arr )   target_sum += it;
        target_sum -= x;
        int l = 0, r = 0, n = arr.size();
        int sum = 0;
        int max_window_size = -1;
        while( r < n ){
            sum += arr[r];
            while( sum > target_sum && l <= r ){
                sum -= arr[l];
                l++;
            }
            if( sum == target_sum ) max_window_size = max(max_window_size, r-l+1);
            r++;
        }
        if( max_window_size == -1 ) return -1;
        return n - max_window_size;
    }
};