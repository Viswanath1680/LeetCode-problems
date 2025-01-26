class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for( int i = 0 ; i < n ; i++){
            int actual = nums[i] - 1;
            if( nums[actual] != nums[i] ){
                swap( nums[actual], nums[i] );
                i--;
            }
        }
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ ){
            if( nums[i] != i+1 )    ans.push_back(nums[i]);
        }
        return ans;
    }
};