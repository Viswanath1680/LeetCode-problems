class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int ans = 0, n = arr.size();
        for( int i = 0; i < n; i++ ){
            int j = i, temp = 1;
            while( j < n-1 && arr[j] < arr[j+1] ){
                j++, temp++;
            }
            ans = max(ans, temp);
        }
        for( int i = 0; i < n; i++ ){
            int k = i, temp2 = 1;
            while( k < n-1 && arr[k] > arr[k+1] ){
                k++, temp2++;
            }
            ans = max(ans, temp2);
        }

        return ans;
    }
};