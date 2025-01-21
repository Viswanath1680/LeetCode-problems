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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if( !root ) return ans;
        list<TreeNode*> l;
        l.push_back(root);
        bool shouldReverse = false;
        while( l.size() ){
            int n = l.size();
            vector<int> temp;
            while( n-- ){
                TreeNode* iterator = l.front();
                l.pop_front();
                temp.push_back(iterator->val);
                if( iterator->left )    l.push_back(iterator->left);
                if( iterator->right )   l.push_back(iterator->right);
            }
            if( shouldReverse ) reverse( temp.begin(), temp.end() );
            shouldReverse = !shouldReverse;
            ans.emplace_back(temp);
        }
        return ans;
    }
};