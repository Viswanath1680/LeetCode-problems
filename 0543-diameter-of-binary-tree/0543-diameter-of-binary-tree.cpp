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
    int calculateDepth( TreeNode* root ){
        if( !root ) return 0;
        return 1 + max(  calculateDepth(root->left), calculateDepth(root->right));
    }

    // inorder traversal?
    int diameterOfBinaryTree(TreeNode* root) {
        if( !root ) return 0;
        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        return max( leftDepth+rightDepth, max( leftDiameter, rightDiameter ) );
    }
};