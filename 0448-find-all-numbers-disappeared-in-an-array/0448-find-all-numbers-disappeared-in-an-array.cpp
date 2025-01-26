class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for( int i = 0 ; i < n ; i++){
            int actual = nums[i] - 1;
            if( nums[actual] != nums[i] ){
                swap( nums[actual], nums[i] );
                i--;
            }
        }
        for( int i = 0 ; i < n ; i++)
            if( nums[i] != i + 1 )    ans.push_back(i+1);
        return ans;
    }
};