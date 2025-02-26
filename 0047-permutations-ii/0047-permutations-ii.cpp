class Solution {
private:
    void backtrack(vector<int>& arr, set<vector<int>>&s , int ind, int n){
        if( ind == n )    {
            s.insert(arr);
            return;
        }
        for( int i = ind; i < n; i++ ){
            swap(arr[i], arr[ind]);
            backtrack(arr, s, ind+1, n);
            swap(arr[i], arr[ind]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        set<vector<int>> s;
        int n = arr.size();
        vector<vector<int>>ans;
        backtrack(arr, s, 0, n);
        for( auto it : s)   ans.emplace_back(it);
        return ans;
    }
};