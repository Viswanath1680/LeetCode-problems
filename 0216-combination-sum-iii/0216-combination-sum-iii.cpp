class Solution {
public:
    void recursive(vector<vector<int>>&ans, vector<int>arr, vector<int>& temp, int i, int target, int k, int total ){
        if( temp.size() > k )   return;
        if( total == target ){
            if( temp.size() == k ) ans.emplace_back(temp);
            return;
        }
        if( i == 9 || total > target )  return;
        // pick arr[i]
        temp.emplace_back(arr[i]);
        recursive(ans, arr, temp, i+1, target, k, total+arr[i]);
        temp.pop_back();

        // don't pick arr[i]
        recursive(ans, arr, temp, i+1, target, k, total);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int low = k, high = k*9;
        if( n < low || n > high )   return ans;

        vector<int> arr(9, 1);
        for( int i = 1; i < 9; i++ )    arr[i] += arr[i-1];
        vector<int>temp;
        recursive(ans, arr, temp, 0, n, k, 0);
        return ans;
    }
};