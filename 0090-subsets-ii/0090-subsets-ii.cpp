class Solution {
public:
    // Jai Neetcode
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        vector<int>temp;
        sort(arr.begin(),arr.end());

        auto recursive = [&](auto& self, int i) -> void{
            if( i == n ){
                ans.emplace_back(temp);
                return;
            }
            // pick arr[i]
            temp.emplace_back(arr[i]);
            self(self, i+1);
            temp.pop_back();

            // don't pick arr[i] -> skip all the duplicates
            while( i + 1 < n && arr[i] == arr[i+1] )    i++;
            self(self, i+1);
        };

        recursive(recursive, 0);
        return ans;
    }
};