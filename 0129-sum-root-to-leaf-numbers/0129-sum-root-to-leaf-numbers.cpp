class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        
        auto dfs = [&](auto& self, TreeNode* root, int sum) -> void{
            if( !root )     return ;
            if( !root->left && !root->right ){
                sum = sum * 10 + root->val;
                totalSum += sum;
                return;
            }
            sum = sum * 10 + root->val;
            self(self, root->left, sum);
            self(self, root->right, sum);
        };

        dfs(dfs, root, 0);
        return totalSum;
    }
};