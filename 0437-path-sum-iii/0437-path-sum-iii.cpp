using ll = long long;
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int pathsCount = 0;

        auto dfs = [&](auto& self, TreeNode* root, ll sum, unordered_map<ll, int>& ump) -> void{
            if( !root ) return;
            sum += root->val;
            ll diff = sum - targetSum;
            if( ump.find( diff ) != ump.end() ) pathsCount += ump[diff];
            if( sum == targetSum )  pathsCount++;
            ump[sum]++;
            self(self, root->left, sum, ump);
            self(self, root->right, sum, ump);
            ump[sum]--;
            if (ump[sum] == 0) ump.erase(sum);

        };

        unordered_map<ll, int> ump;
        // ump.insert(0);
        dfs(dfs, root, 0, ump);
        return pathsCount;
    }
};