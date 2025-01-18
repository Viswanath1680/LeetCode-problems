class Solution {
public:
    int kadane(vector<int>& arr){
        int max_sum = arr[0], n = arr.size();
        for( int i = 0; i < n; ){
            int sum = 0;
            while( i < n && sum >= 0 ){
                sum += arr[i];
                max_sum = max(max_sum, sum);
                i++;
            }
            sum = 0;
        }
        return max_sum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 )    return nums[0];
        int kadane_sum = kadane(nums);  // normal kadane sum

        // from now, wrap sum calculation
        vector<int> rightMax(n,0);
        int sum = nums[n-1];
        rightMax[n-1] = nums[n-1];
        for( int i = n-2; i >= 0; i-- ){
            sum += nums[i];
            rightMax[i] = max(sum, rightMax[i+1]);
        }
        int prefixSum = 0, sum2 = INT_MIN;
        for( int i = 0; i < n-1; i++ ){
            prefixSum += nums[i];
            sum2 = max(sum2, prefixSum + rightMax[i+1] );
        }
        return max(kadane_sum, sum2);
    }
};