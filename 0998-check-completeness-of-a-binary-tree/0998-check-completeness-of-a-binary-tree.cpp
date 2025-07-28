class Solution {
public:
    int depth(TreeNode* root){
        if (!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }


    bool isCompleteTree(TreeNode* root) {
        if( !root ) return true;
        int h = depth(root);
        int depth = 1;
        queue<TreeNode*> q;
        q.push(root);
        // until h-1, there should not be any nullptr
        while( !q.empty() && depth < h-1 ){
            int n = q.size();
            while( n-- ){
                auto node = q.front(); q.pop();
                if( !node->left )   return false;
                if( !node->right )  return false;
                q.push( node->left );
                q.push( node->right );
            }
            depth++;
        }
        // Now we have the parents of leaves in the queue
        bool isNullPtrFound = false;
        while( !q.empty() ){
            auto node = q.front(); q.pop();
            if( node->left || node->right ){
                if( isNullPtrFound )    return false;
            }
            // all 4 cases
            if( node->left && node->right ) continue;
            if( !node->left && node->right  )   return false;
            if( node->left && !node->right )    isNullPtrFound = true;
            if( !node->left && !node->right )   isNullPtrFound = true;
        }
        return true;
    }
};