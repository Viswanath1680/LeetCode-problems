class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 )    return nums[0];
        if( n == 2 )    return min( nums[0], nums[1] );
        int l = 0, r = n-1;
        int mid;
        while( l <= r ){
            if( nums[l] < nums[r] )   return nums[l];
            if( l == r )    return nums[l];
            mid = l + ( r- l )/2;
            if( mid > 0 && mid < n-1 ){
                if( nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1] )
                    return nums[mid];
            }
            if( nums[mid] < nums[l] )    r = mid-1;
            else    l = mid + 1;
        }
        return nums[mid];
    }
};