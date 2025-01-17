class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>ans;
        ans.emplace_back( pref[0] );
        for( int i = 1; i < pref.size(); i++ )  ans.emplace_back( pref[i] ^ pref[i-1] );
        return ans;
    }
};