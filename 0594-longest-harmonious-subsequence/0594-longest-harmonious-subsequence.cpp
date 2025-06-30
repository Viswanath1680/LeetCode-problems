class Solution {
public:
    int findLHS(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        unordered_map<int, int> ump;
        for( auto it : arr )    ump[it]++;
        for( auto [key, freq] : ump ){
            int freq2 = ump.find( key + 1 ) != ump.end() ? ump[key+1] : 0;
            if( freq2 )    ans = max(ans, freq+freq2);
        }
        return ans;
    }
};