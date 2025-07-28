class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size() , max_or = 0;
        for( auto it : nums )   max_or =  max_or | it;
        int count = 0;
        
        auto dfs = [&](auto& self, int i, int or_val, vector<int>& arr) -> void{
            if( i == n ){
                if( or_val == max_or )  count++;
                return;
            }
            arr.emplace_back(nums[i]);
            self(self, i+1, (or_val|nums[i]), arr );
            arr.pop_back();

            self(self, i+1, or_val, arr);
        };

        vector<int> arr;
        dfs(dfs, 0, 0, arr);
        return count;
    }
};