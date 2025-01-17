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
    void inOrderTraversal( TreeNode* root, vector<int>& ans ){
        if( root == nullptr )   return;
        inOrderTraversal(root->left, ans);
        ans.emplace_back(root->val);
        inOrderTraversal(root->right, ans);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> inOrder;
        inOrderTraversal(root, inOrder);
        for(int i = 1; i < inOrder.size(); i++ ){
            if( inOrder[i] <= inOrder[i-1] )    return false;
        }
        return true;
    }
};