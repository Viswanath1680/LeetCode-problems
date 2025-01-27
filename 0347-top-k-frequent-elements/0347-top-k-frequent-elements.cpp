class Solution {
public:
    static bool comparator( pair<int,int> &a, pair<int,int> &b ){
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for( auto it : nums )
            mp[ it ]++;
        vector<int> ans;
        // mp.clear();
        vector<pair<int,int>> arr;
        for( auto it : mp )
            arr.emplace_back( it );
        sort( arr.begin(), arr.end(), comparator );
        for( int i = 0 ; i < k ; i++ )  ans.emplace_back( arr[i].first );
        return ans;
    }
};