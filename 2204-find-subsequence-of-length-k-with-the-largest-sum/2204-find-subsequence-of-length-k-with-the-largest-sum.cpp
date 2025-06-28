class Solution {
public:
    vector<int> maxSubsequence(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<int, int>> indexed;
        for (int i = 0; i < n; ++i)    indexed.emplace_back(arr[i], i);

        sort(indexed.begin(), indexed.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        vector<pair<int, int>> top_k(indexed.begin(), indexed.begin() + k);

        sort(top_k.begin(), top_k.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });

        vector<int> ans;
        for (auto &[val, idx] : top_k)    ans.push_back(val);

        return ans;
    }
};
