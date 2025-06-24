class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& arr, int key, int k) {
        vector<int> ans;
        set<int> s, s2;
        int n = arr.size();
        for( int i = 0; i < n; i++ )    if( arr[i] == key ) s.insert(i);
        for( auto ind : s ){
            int low = max(0, ind-k);
            int high = min(n-1, ind+k);
            for( int i = low; i <= high; i++ )  s2.insert(i);
        }
        for( auto it : s2 ) ans.emplace_back(it);
        return ans;
    }
};