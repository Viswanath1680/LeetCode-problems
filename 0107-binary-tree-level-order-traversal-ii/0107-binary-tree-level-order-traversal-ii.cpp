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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if( !root ) return ans;
        list<TreeNode*> l;
        TreeNode* iterator;
        l.push_back(root);
        while( l.size() ){
            vector<int> temp;
            int n = l.size();
            for( int i = 0; i < n ; i++ ){
                iterator = l.front();
                l.pop_front();
                temp.push_back( iterator->val );
                if( iterator->left )    l.push_back(iterator->left);
                if( iterator->right )   l.push_back( iterator->right );
            }
            ans.emplace_back(temp);
        }
        reverse( ans.begin(), ans.end() );
        return ans;
    }
};