class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        set<vector<int>> ans_set;
        int n = arr.size();
        int psize = 1 << n;
        for( int i = 0; i < psize; i++ ){
            vector<int>temp;
            for(int j = 0; j < n; j++){
                if( i & (1 << j) )  temp.emplace_back(arr[j]);
            }
            ans_set.insert( temp );
        }
        vector<vector<int>>ans;
        for( auto it : ans_set )    ans.emplace_back( it );
        return ans;
    }
};