class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int sum = arr[0], ans = arr[0], i = 1;
        while( i < arr.size() ){
            while( sum >= 0 && i < arr.size() ){
                sum += arr[i++];
                ans = max(ans, sum);
            }
            sum = 0;
        }
        return ans;
    }
};