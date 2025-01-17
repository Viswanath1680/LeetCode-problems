class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        int psize = 1 << arr.size();
        for( int i = 0; i < psize; i++ ){
            vector<int> temp;
            for( int j = 0; j < arr.size(); j++ ){
                if( i & (1 << j ) )     temp.emplace_back(arr[j]);
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};