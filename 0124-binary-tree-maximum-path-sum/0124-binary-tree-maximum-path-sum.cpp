class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        if( !root ) return 0;

        auto sum = [&](auto& self, TreeNode* root) -> int{
            if( !root ) return 0;
            auto left = self(self, root->left);
            auto right = self(self, root->right);
        //same as diameter question:
            // ans = max(ans, left+right);
            // return max(left, right) + 1;
            auto val = root->val;
            ans = max(ans, val);
            ans = max(ans, left + val);
            ans = max(ans, right+val);
            ans = max(ans, left + right + val );

            // now return maximum possible sum from this root
            return max(max(left, right) + root->val, root->val);
        };
        sum(sum, root);
        return ans;
    }
};