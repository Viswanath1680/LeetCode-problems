class Solution {
public:
    int countCompleteSubarrays(vector<int>& arr) {
        set<int> s;
        for( auto it : arr )    s.emplace(it);
        int distinct = s.size();
        s.clear();

        int n = arr.size(), i = 0, j = 0;
        unordered_map<int, int> ump;
        int ans = 0;
        while( j < n ){
            ump[ arr[j] ]++;
            while( ump.size() == distinct ){
                ans += n-j;
                ump[arr[i]]--;
                if( ump[arr[i]] == 0 )  ump.erase( arr[i] );
                i++;
            }
            j++;
        }
        return ans;
    }
};