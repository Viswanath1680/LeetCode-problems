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
void populateMapLevel(vector<TreeNode*>& nums, vector<int>& levels, string& traversal){
    int count = 0, num = 0;
    for(int i = 0; i < traversal.size(); i++){
        if(traversal[i] == '-') {
            if(traversal[i-1] != '-'){
                levels.push_back(count);
                nums.push_back(new TreeNode(num));
                count = 0, num = 0;
            }
            count++;
        }
        else num = num * 10 + traversal[i] - '0';
    }
    levels.push_back(count);
    nums.push_back(new TreeNode(num));
}

public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> nums;
        vector<int> levels;
        populateMapLevel(nums, levels, traversal);
        // for(int i = 0; i < nums.size(); i++) cout << nums[i] << " " << levels[i] << "\n";
        for(int i = 1; i < nums.size(); i++){
            TreeNode* curr = nums[i];
            for(int j = i - 1; j >= 0; j--){
                if(levels[i] - levels[j] == 1) {
                    if(nums[j]->left) nums[j]->right = curr;
                    else nums[j]->left = curr;
                    break;
                }
            }
        }
        return nums[0]; // this is the root
    }
};