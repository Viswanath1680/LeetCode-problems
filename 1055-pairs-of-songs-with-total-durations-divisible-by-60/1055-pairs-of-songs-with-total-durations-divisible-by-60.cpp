class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& arr) {
        for( auto & it : arr )  it = it % 60;
        unordered_map<int,int> ump;
        int ans = 0;
        for( int i = 0 ; i < arr.size(); i++ ){
            int target =  ( 60 - arr[i] ) % 60;
            ans += ump[ target ];
            ump[ arr[i] ]++; 
        }
        return ans;
    }
};