class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n,0) , suffix(n, 0);
        prefix[0] = arr[0];
        for( int i = 1; i < n; i++ )    prefix[i] = max(arr[i], prefix[i-1] );
        suffix[n-1] = arr[n-1];
        for( int i = n-2; i >= 0; i-- ) suffix[i] = max(arr[i], suffix[i+1] );
        
        int ans = 0;
        for( int i = 0; i < n; i++)    ans += min( prefix[i], suffix[i] ) - arr[i];
        return ans;
    }
};