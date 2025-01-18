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
    unordered_map<TreeNode*, int> ump;
    int height( TreeNode* root ){
        if( root == nullptr )   return ump[ root ] = 0;
        if( ump.find( root ) != ump.end() ) return ump[root];
        ump[ root->left ] = height( root->left );
        ump[ root->right ] = height( root->right );
        return ump[ root ] = 1 + max( ump[root->left], ump[root->right] );
    }

    bool check( TreeNode* root ){
        if( root == nullptr )   return true;
        return ( abs( ump[root->left] - ump[ root->right ] ) <= 1 && check( root->left ) && check( root->right ) );
    }

    bool isBalanced(TreeNode* root) {
        height( root );
        return check(root);
    }
};