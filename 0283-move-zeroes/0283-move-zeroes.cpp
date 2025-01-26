class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), zero = 0;
        for( int i = zero; i < n ; i++ ){
            if( nums[i] != 0 ){
                swap( nums[i], nums[zero] );
                zero++;
            }
        }
    }
};