class Solution {
public:
    int maxAscendingSum(vector<int>& arr) {
        int ans = *max_element(arr.begin(), arr.end());
        int n = arr.size();
        for( int i = 0; i < n; i++ ){
            int temp = 0;
            while( i < n-1 && arr[i] < arr[i+1] ){
                temp += arr[i];
                i++;
            }
            temp += arr[i];
            ans = max(ans, temp);
        }
        return ans;
    }
};