class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
         for (int i = 0; i <= n - k; ++i) {
            set<int> seen; 
            
            for (int j = i; j < i + k; ++j) {
                if (seen.find(nums[j]) == seen.end()) {  
                    mp[nums[j]]++;  
                    seen.insert(nums[j]);
                }
            }
        }
        int maxi = -1;
        for( auto it : mp )  if( it.second == 1 )     maxi = max(maxi, it.first);
        return maxi;
    }
};