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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if( !root ) return ans;
        queue<TreeNode*> l;
        l.emplace( root );
        while( l.size() ){
            int n = l.size();
            vector<int>temp;
            while( n-- ){
                TreeNode* node = l.front();
                temp.emplace_back( node->val );
                if( node->left )    l.emplace( node->left );
                if( node->right )   l.emplace( node->right );
                l.pop();
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};