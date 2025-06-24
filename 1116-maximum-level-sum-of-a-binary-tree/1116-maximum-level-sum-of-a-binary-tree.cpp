class Solution {
public:
    // level order traversal and update sum, level
    int maxLevelSum(TreeNode* root) {
        if( !root ) return 1;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0, ans = 0;
        int sum = INT_MIN;
        while( q.size() ){
            int n = q.size();
            level++;
            int temp_sum = 0;
            while( n-- ){
                auto node = q.front();
                q.pop();
                temp_sum += node->val;
                if( node->left )    q.push( node->left );
                if( node->right )   q.push( node->right );
            }
            if( temp_sum > sum ){
                sum = temp_sum;
                ans = level;
            }
        }
        return ans;
    }
};