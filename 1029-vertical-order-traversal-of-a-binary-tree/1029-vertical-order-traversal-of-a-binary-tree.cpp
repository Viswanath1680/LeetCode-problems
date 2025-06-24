class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int, int>, vector<int>> mp;
        int leftmost = 0, rightmost = 0;
        auto recursive = [&](auto& self, TreeNode* root, int row, int column) -> void{
            if( !root ) return;
            leftmost = min(leftmost, column);
            rightmost = max(rightmost, column);
            mp[{row, column}].emplace_back(root->val);
            self(self, root->left, row+1, column-1);
            self(self, root->right, row+1, column+1);
        };

        recursive(recursive, root, 0, 0);
        map<int, vector<pair<int, vector<int>>>> colMap;
        for (const auto& [key, vals] : mp) {
            int row = key.first;
            int col = key.second;
            colMap[col].emplace_back(row, vals);
        }

        vector<vector<int>> result;

        for (auto& [col, rowValsVec] : colMap) {
            sort(rowValsVec.begin(), rowValsVec.end(), [](auto& a, auto& b) {
                return a.first < b.first;
            });

            vector<int> temp;

            for (auto& [row, vals] : rowValsVec) {
                sort(vals.begin(), vals.end());
                temp.insert(temp.end(), vals.begin(), vals.end());
            }

            result.push_back(temp);
        }
        return result;
    }
};