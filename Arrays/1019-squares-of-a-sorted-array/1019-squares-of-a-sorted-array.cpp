class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        vector<int> answer;
        while( l <= r ){
            if( abs(nums[l]) > abs(nums[r]) ){
                answer.emplace_back( nums[l] * nums[l] );
                l++;
            }
            else{
                answer.emplace_back( nums[r] * nums[r] );
                r--;
            }
        }
        reverse( answer.begin(), answer.end() );
        return answer;
    }
};