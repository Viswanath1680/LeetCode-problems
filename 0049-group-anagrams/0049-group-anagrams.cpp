class Solution {
public:
// iterate over strs and sort them. Store their index in the map.
// then append all indices in a key in a single vector.
// return the vector<vector>>
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> mp;
        int i = 0;
        for( auto temp : strs ){
            sort( temp.begin(), temp.end() );
            mp[ temp ].emplace_back(i);
            i++;
        }
        vector<vector<string>> ans;
        for( auto outer : mp ){
            vector<string> temp;
            for( auto ind : outer.second )
                temp.emplace_back( strs[ind] );
            ans.emplace_back(temp);
        }
        return ans;
    }
};
