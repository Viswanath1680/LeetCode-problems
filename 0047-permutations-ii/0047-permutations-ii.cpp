// Neetcode way
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> answer;

        auto dfs = [&](auto& self, vector<int>& arr, unordered_map<int, int>& ump) -> void{
            if( arr.size() == n ){
                answer.push_back(arr);
                return;
            }
            for( auto [num, count] : ump ){
                if( count == 0 )    continue;
                ump[num]--;
                // if( ump[num] == 0 ) ump.erase(num);  -> Causes heap-use-after-free bug
                arr.emplace_back(num);
                self(self, arr, ump);
                arr.pop_back();
                ump[num]++; // backtrack
            }
        };
        
        vector<int> arr;
        unordered_map<int, int> ump;
        for( auto it : nums )    ump[it]++;
        dfs(dfs, arr, ump);
        return answer;
    }
};