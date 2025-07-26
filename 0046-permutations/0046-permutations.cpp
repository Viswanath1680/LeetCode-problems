// backtracking. Use a decision tree to visualize
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> answer;
        auto dfs = [&](auto& self, set<int>& s, vector<int>& arr) -> void{
            if( arr.size() == n ){
                answer.push_back(arr);
                return;
            }
            for( int i = 0; i < n; i++ ){
                if( s.count(i) )    continue;
                s.insert( i );
                arr.push_back(nums[i]);
                self(self, s, arr);
                arr.pop_back();
                s.erase(i);
            }
        };
        vector<int> arr;
        set<int> s;
        dfs(dfs, s, arr);
        return answer;
    }
};