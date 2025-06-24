class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if( !root ) return root;
        vector<vector<int>> arr;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while( q.size() ){
            int n = q.size();
            vector<int> temp;
            while( n-- ){
                auto node = q.front();
                q.pop();
                if( level & 1 ) temp.emplace_back(node->val);
                if( node->left )    q.push(node->left);
                if( node->right ) q.push( node->right );
            }
            if( level & 1 ){
                reverse(temp.begin(), temp.end());
                arr.emplace_back(temp);
            }
            level++;
        }

        q.push( root );
        level = 0;
        while( q.size() ){
            int n = q.size(), i = 0;
            while( n-- ){
                auto node = q.front();
                q.pop();
                if( node->left )    q.push(node->left);
                if( node->right ) q.push( node->right );
                if( level & 1 ) node->val = arr[level/2][i++];
            }
            level++;
        }
        return root;
    }
};