class Solution {
public:
    // Neetcode Solution

    void recursive(vector<vector<int>>& ans, vector<int>& arr, vector<int>& temp, int i, int total, int target){
        if( target == total ){
            ans.emplace_back(temp);
            return;
        }
        if( total > target || i == arr.size() )  return;

        temp.emplace_back(arr[i]);
        recursive(ans, arr, temp, i, total+arr[i], target);

        temp.pop_back();
        recursive(ans, arr, temp, i+1, total, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recursive(ans, candidates, temp, 0, 0, target);
        return ans;
    }
};