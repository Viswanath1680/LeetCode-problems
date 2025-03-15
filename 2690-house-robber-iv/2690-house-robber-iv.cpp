class Solution {
public:
    int minCapability(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 1, r = *max_element(arr.begin(), arr.end());
        int ans = r;
        while( l <= r ){
            int mid = l + (r-l)/2;
            int count = 0;
            for( int i = 0; i < n; ){
                if( arr[i] <= mid ){
                    count++, i += 2;
                }
                else    i++;
            }
            if( count >= k ){
                r = mid-1;
                ans = mid;
            }
            else    l = mid + 1;
        } 
        return ans;
    }
};