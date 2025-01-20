class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        for( int i = 0 ; i < n ; i++){
            if( nums[i] == n )  continue;
            int actual = nums[i];
            if( nums[actual] != nums[i] ){
                swap( nums[actual], nums[i] );
                i--;
            }
        }
        for( int i = 0 ; i < n ; i++)
            if( nums[i] != i )      return i;
        return n;
    }
};