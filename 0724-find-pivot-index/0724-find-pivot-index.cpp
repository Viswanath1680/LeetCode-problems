class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 )    return n-1;
        vector<int> fwdsum(n), bcwdsum(n);
        fwdsum[0] = nums[0];
        bcwdsum[n-1] = nums[n-1];
        for( int i = 1; i < n; i++ )    fwdsum[i] = nums[i] + fwdsum[i-1];
        for( int i = n-2; i >= 0; i-- ) bcwdsum[i] = nums[i] + bcwdsum[i+1];

        if( bcwdsum[1] == 0 )    return 0;
        
        for( int i = 1; i < n-1; i++ )
            if( fwdsum[i-1] == bcwdsum[i+1] )   return i;
        
        if( fwdsum[n-2] == 0 )  return n-1;
        return -1;
    }
};