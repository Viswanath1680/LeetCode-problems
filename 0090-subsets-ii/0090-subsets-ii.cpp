void Print(int Pointer, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans) {
    if (Pointer == arr.size()) {
        ans.emplace_back(temp);
        return;
    }
    temp.emplace_back(arr[Pointer]);
    Print(Pointer + 1, arr, temp, ans);
    temp.pop_back();
    Print(Pointer + 1, arr, temp, ans);
    return;
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort( nums.begin(), nums.end() );
        Print(0, nums, temp, ans);

        set<vector<int>> ans_set;
        for (auto it : ans)
            ans_set.insert(it);

        ans.clear();
        for (auto it : ans_set)
            ans.emplace_back(it);

        return ans;
    }
};
