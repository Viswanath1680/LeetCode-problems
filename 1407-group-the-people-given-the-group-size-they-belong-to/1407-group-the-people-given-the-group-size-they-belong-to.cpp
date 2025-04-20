class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        unordered_map<int, vector<int>> ump;
        int n = arr.size();
        vector<vector<int>> ans;
        for( int i = 0; i < n; i++){ 
            if( arr[i] == 1 )    ans.emplace_back(vector<int>{i} );
            else    ump[ arr[i] ].emplace_back(i);
        }
        for( auto it : ump ){
            n = it.first;   // 3 in example case 1
            vector<int> newarr = it.second;
            int k = newarr.size();  // 6
            // 0 -> 2, 3 -> 5
            int i = 0;
            vector<int> temp;
            while( i < k ){
                temp.emplace_back( newarr[i] );
                i++;
                if( i % n == 0 ){
                    ans.emplace_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};