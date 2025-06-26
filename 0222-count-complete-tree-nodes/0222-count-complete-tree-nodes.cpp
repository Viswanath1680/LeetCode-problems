class Solution {
public:
    bool isNodeExist(TreeNode* root, int mid){
        string path = "";
        while( mid > 1 ){
            if( mid&1 )    path += '1';
            else    path += '0';
            mid = mid >> 1;
        }
        // cout << " path " << path << "\n";
        int n = path.size();
        auto curr = root;
        for( int i = n-1; i >= 0; i-- ){
            if( path[i] == '1' ){
                if( !curr->right )  return false;
                curr = curr->right;
            }
            else{
                if( !curr->left )   return false;
                curr = curr->left;
            }
        }
        return true;
    }

    int binarySearch( TreeNode* root, int level ){
        int l = ( 1 << level-1 ), r = (1 << level) - 1;
        int l_copy = l;
        int ans;
        while( l <= r ){
            // cout << " l " << l << " r " << r ;
            int mid = (l + r) / 2;
            // cout << " mid " << mid;
            if( isNodeExist(root, mid) ){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        // cout << ans << "\n";
        return ( ans - l_copy + 1 ) ;
    }

    int countNodes(TreeNode* root) {
        if( !root ) return 0;
        int left_level = -1, right_level = -1; 
        auto left = root, right = root;
        while( left ){
            left = left->left;
            left_level++;
        }
        while( right ){
            right = right->right;
            right_level++;
        }
        // cout << left_level << "\n";
        if( left_level == right_level ) return pow(2, left_level+1) - 1;

        // assume l = left_level
        // leftmost node is 0, rightmost node is 2^l - 1
        // Convert number into binary. 0 -> left, 1 -> right
        int last_level_nodes = binarySearch(root, left_level+1);
        // cout << last_level_nodes;
        return ( pow(2, left_level) - 1 + last_level_nodes );
    }
};