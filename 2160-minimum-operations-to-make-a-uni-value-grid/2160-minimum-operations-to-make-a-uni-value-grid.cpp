class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        for( auto outer : grid )
            for( auto it : outer )  arr.push_back(it);
        sort( arr.begin(), arr.end() );
        int n = arr.size();
        int med = arr[n/2];
        int ans = 0;
        for( auto it : arr ){
            int diff = abs(it - med);
            if( diff % x )  return -1;
            ans += diff/x;
        }
        return ans;
    }
};