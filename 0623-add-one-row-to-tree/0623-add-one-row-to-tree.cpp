// do level order until depth-1 and add new nodes
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if( depth == 1 ){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        int d = 1;
        queue<TreeNode*> q;
        q.push( root );
        while( !q.empty() && d < depth-1 ){
            int n = q.size();
            while( n-- ){
                auto node = q.front(); q.pop();
                if( node->left )    q.push( node->left );
                if( node->right )   q.push( node->right );
            }
            d++;
        }
        // now we have all the nodes in the level d-1
        while( !q.empty() ){
            auto node = q.front(); q.pop();
            auto newN = new TreeNode(val);
            newN->left = node->left;
            node->left = newN;
            auto newN2 = new TreeNode(val);
            newN2->right = node->right;
            node->right = newN2;
        }
        return root;
    }
};