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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> levelOrder;
        vector<int> ans;
        if( !root ) return ans;
        list<TreeNode*> l;
        l.push_back( root );
        while( l.size() ){
            vector<int> temp;
            int n = l.size();
            for( int i = 0; i < n; i++ ){
                TreeNode* tempnode = l.front();
                l.pop_front();
                temp.push_back( tempnode->val );
                if( tempnode->left )    l.push_back( tempnode->left );
                if( tempnode->right )   l.push_back( tempnode->right );
            }
            levelOrder.push_back( temp );
        }
        for( auto arr : levelOrder ){
            int n = arr.size();
            ans.push_back( arr[n-1] );
        }
        return ans;
    }
};