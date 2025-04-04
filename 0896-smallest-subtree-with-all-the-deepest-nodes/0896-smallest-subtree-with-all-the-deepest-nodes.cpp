/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int Depth(TreeNode* root, unordered_map<TreeNode*,int>& ump){
        if( root == nullptr )   return 0;
        if (ump.find(root) != ump.end())    return ump[root];

        int leftDepth = -1;
        if (root->left)    leftDepth = Depth(root->left, ump);
        int rightDepth = -1;
        if (root->right)    rightDepth = Depth(root->right, ump);

        ump[root] = 1 + max(leftDepth, rightDepth);
        
        return ump[root];
    }

    TreeNode* recursive(TreeNode* root, unordered_map<TreeNode*, int>&ump, int maxDepth){
        if( root == nullptr )   return root;
        if (ump[root] == maxDepth && root->left == nullptr && root->right == nullptr) {
            return root;
        }
        TreeNode* left = recursive(root->left, ump, maxDepth-1);
        TreeNode* right = recursive(root->right, ump, maxDepth-1);

        if ( left && right )    return root;
        return left ? left : right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, int> ump;
        Depth(root, ump);
        // depth of every node is now calculated

        int maxDepth = ump[root];
        return recursive(root, ump, maxDepth);
    }
};