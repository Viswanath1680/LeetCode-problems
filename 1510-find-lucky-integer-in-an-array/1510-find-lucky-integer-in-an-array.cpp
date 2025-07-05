class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> ump;
        for( auto it : arr )    ump[it]++;
        int ans = -1;
        for( auto [key, freq] : ump )   {
            if( key == freq )   ans = max(ans, key);
        }
        return ans;
    }
};