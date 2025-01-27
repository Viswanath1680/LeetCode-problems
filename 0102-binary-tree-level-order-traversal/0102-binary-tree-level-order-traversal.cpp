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
        if( root == nullptr )  return ans;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        while( !q1.empty() || !q2.empty() ){
            vector<int> tempArr;
            while( !q1.empty() ){
                TreeNode* tempNode = q1.front();
                if( tempNode ){
                    if( tempNode->left ) q2.push(tempNode->left);
                    if( tempNode->right ) q2.push(tempNode->right);
                    tempArr.emplace_back(tempNode->val);
                }
                q1.pop();
            }
            ans.emplace_back(tempArr);
            q1.swap(q2);
        }
        return ans;
    }
};