class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> ump;
        unordered_set<int> isChild;
        for( auto v : descriptions ){
            int parent = v[0], child = v[1];
            if( ump.find( parent ) == ump.end() )   {
                auto parent_node = new TreeNode(parent);
                ump[parent] = parent_node;
            }
            if( ump.find(child) == ump.end() ){
                auto child_node = new TreeNode(child);
                ump[child] = child_node;
            }
            isChild.insert(child);
            if( v[2] )  ump[parent]->left = ump[child];
            else    ump[parent]->right = ump[child];
        }
        for( auto [parent, parent_node] : ump ){
            if( isChild.find( parent ) == isChild.end() )   return parent_node;
        }
        return nullptr;
    }
};