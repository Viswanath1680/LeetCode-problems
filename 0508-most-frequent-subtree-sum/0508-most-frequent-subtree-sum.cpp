class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> ump;
        auto dfs = [&](auto& self, TreeNode* root) -> int{
            if( !root ) return 0;
            int left = self(self, root->left);
            int right = self(self, root->right);
            int sum = left + right + root->val;
            ump[ sum ]++;
            return sum;
        };

        dfs(dfs, root);
        int max_frequency = 0;
        for( auto [sum, freq] : ump )   max_frequency = max(max_frequency, freq);
        vector<int> ans;
        for( auto [sum, freq] : ump )   if( freq == max_frequency ) ans.emplace_back(sum);
        return ans;
    }
};