class Solution {
public:
    // example case, nums1 = [3,2,0,1,0], nums2 = [6,5,0]
    // Add 1s instead of 0s, 8 and 12 -> minimum possibility = 12
    long long minSum(vector<int>& arr1, vector<int>& arr2) {
        long long sum1 = 0, sum2 = 0;
        int z1 = 0, z2 = 0;
        for( auto it : arr1 )   {
            sum1 += it;
            if( it == 0 ){
                sum1++;
                z1++;
            }
        }
        for( auto it : arr2 )   {
            sum2 += it;
            if( it == 0 ){
                sum2++;
                z2++;
            }
        }
        // -1 cases:
        if( z1 == 0 ){
            if( z2 == 0 && sum1 != sum2 )   return -1;
            if( sum1 < sum2 )   return -1;
        }
        if( z2 == 0 ){
            if( sum2 < sum1 )   return -1;
        }
        return max(sum1, sum2);
    }
};