class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*, int> ump;
        ump[nullptr] = 0;
        // computes size of every node in the tree and stores
        auto compute_size = [&](auto& self, TreeNode* root) -> int{
            if( !root ) return 0;
            ump[root] = 1 + self(self, root->left) + self(self, root->right);
            return ump[root];
        };

        compute_size(compute_size, root);

        // Now binary search for k
        // crucial step while going to root->right: k-left_size-1 so that we skip entire root->left and root 
        auto binary_search = [&](auto& self, TreeNode* root, int k) -> int{
            int left_size = ump[root->left];
            if( k == left_size + 1 )    return root->val;
            else if( k <= left_size ) return self(self, root->left, k);
            return self(self, root->right, k-left_size-1);
        };        

        return binary_search(binary_search, root, k);
    }
};