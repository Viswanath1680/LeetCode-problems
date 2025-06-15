class Solution {
public:
    // Neetcode Solution
    void recursive(vector<vector<int>>& ans, vector<int>& arr, vector<int>& temp, int i, int target, int total){
        int n = arr.size();
        if( target == total ){
           ans.emplace_back(temp);
           return ; 
        }
        if( i == n || total > target )  return;
        
        // pick arr[i]
        temp.emplace_back(arr[i]);
        recursive(ans, arr, temp, i+1, target, total+arr[i]);
        temp.pop_back();

        // don't pick arr[i] -> skip all the duplicate vals of arr[i]
        while( i+1 < n && arr[i] == arr[i+1] )  i++;
        recursive(ans, arr, temp, i+1, target, total);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        recursive(ans, candidates, temp, 0, target, 0);
        return ans;
    }
};