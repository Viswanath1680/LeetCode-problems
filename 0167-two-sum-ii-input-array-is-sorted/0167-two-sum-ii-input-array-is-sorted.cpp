class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> ans;
        int l = 0, r = n-1;
        while( l < r ){
            int sum = arr[l] + arr[r];
            if( sum == target ){
                ans.emplace_back( l+1 );
                ans.emplace_back( r+1 );
                break;
            }
            else if( sum < target )
                l++;
            else
                r--;
        }
        return ans;
    }
};