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
    vector<int> LevelsSum(TreeNode* root){
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while( q.size() ){
            int n = q.size(), sum = 0;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if( node->left )    q.push(node->left);
                if( node->right )   q.push(node->right);
            }
            ans.emplace_back(sum);
        }
        return ans;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelsum = LevelsSum(root);
        root->val = 0;
        queue<TreeNode*> q;
        int i = 0;
        q.push(root);
        while( q.size() ){
            i++;
            int n = q.size();
            while(n--){
                int sibling_sum = 0;
                TreeNode* node = q.front();
                q.pop();
                if( node->left )    sibling_sum += node->left->val;
                if( node->right )   sibling_sum += node->right->val;

                if( node->left ){    
                    node->left->val = levelsum[i] - sibling_sum;
                    q.push(node->left);
                }
                if( node->right ){   
                    node->right->val = levelsum[i] - sibling_sum;
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};