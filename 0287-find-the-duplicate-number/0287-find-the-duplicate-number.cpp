class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for( int i = 0 ; i < nums.size(); i++ ){
            int index = nums[i] - 1;
            if( nums[i] != nums[index] ){
                swap( nums[i], nums[ index] );
                i--;
            }
        }
        for( int i = 0; i < nums.size(); i++ )
            if( nums[i] - 1 != i  ) return nums[i];
        return nums[0];
    }
};