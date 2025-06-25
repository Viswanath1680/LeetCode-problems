class Solution {
public:
    // Biggest Hint: assign col number to each node
    int widthOfBinaryTree(TreeNode* root) {
        if( !root ) return 0;
        unsigned long long ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while( q.size() ){
            int n = q.size();
            unsigned long long min_col = ULLONG_MAX, max_col = 0;
            while( n-- ){
                auto [node, col] = q.front();
                // cout << col << " ";
                q.pop();
                min_col = min(min_col, col);
                max_col = max(col, max_col);
                if( node->left )    q.push( {node->left, 2*col} );
                if( node->right )   q.push( {node->right, 2*col+1} );
            }
            // cout << endl;
            ans = max(ans, (max_col - min_col+1));
        }
        return ans;
    }
};