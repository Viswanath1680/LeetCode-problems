class Solution {
public:
    int partitionArray(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int ans = 0;
        for( int i = 0; i < n; i++){
            int ind = i;
            while( ind < n && arr[ind] - arr[i] <= k )  ind++;
            i = ind-1;
            ans++;
        }
        return ans;
    }
};