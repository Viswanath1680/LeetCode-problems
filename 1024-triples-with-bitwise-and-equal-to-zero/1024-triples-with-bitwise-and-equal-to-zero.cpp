class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        unordered_map<int, int> ump;
        for( auto a : arr )
            for( auto b : arr )
                ump[ a&b ]++;

        for( auto a : arr )
            for( auto it : ump )
                if( (a & it.first) == 0  )  ans += it.second;

        return ans;
    }
};