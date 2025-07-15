// without follow up
class BSTIterator {
private:
    int ptr = -1;
    vector<int> inorder_traversal;
    int size;
public:
    BSTIterator(TreeNode* root) {

        auto inorder = [&](auto& self, TreeNode* root) -> void{
            if( !root ) return;
            self(self, root->left);
            inorder_traversal.emplace_back(root->val);
            self(self, root->right);
        };
        inorder(inorder, root);
        size = inorder_traversal.size();
    }
    
    int next() {
        return inorder_traversal[ ++ptr ];
    }
    
    bool hasNext() {
        return (ptr + 1 < size );
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */