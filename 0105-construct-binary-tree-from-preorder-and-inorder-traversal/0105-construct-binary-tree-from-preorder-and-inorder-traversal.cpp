class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> ump;
        for (int i = 0; i < inorder.size(); ++i)    ump[inorder[i]] = i;
        int preIndex = 0;
        auto recursive = [&](auto& self, int start, int end) -> TreeNode*{
            if( start > end )   return nullptr;
            int rootval = preorder[preIndex++];
            auto root = new TreeNode(rootval);
            int inorder_index = ump[ rootval ];
            root->left = self(self, start, inorder_index-1);
            root->right = self(self, inorder_index + 1, end);
            return root;
        };
        auto root = recursive(recursive, 0, inorder.size()-1);
        return root;
    }
};