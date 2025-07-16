// Pick a subsequence which is alternate
// also maintain count of evens and odds
// max of these 3 vars is the answer
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 0, alternate = 1;
        if( nums[0] % 2 )   odd++;
        else    even++;
        int j = 0;
        for( int i = 1 ; i < n ; i++ ){
            if( nums[i] % 2 != nums[j] % 2 ){
                alternate++;
                j = i;
            }
            if( nums[i] % 2 )   odd++;
            else    even++;
        }
        return max( alternate, max(even, odd) );
    }
};