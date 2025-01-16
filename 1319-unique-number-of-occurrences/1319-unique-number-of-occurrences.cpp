class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> ump;
        for( auto it : arr )    ump[it]++;
        unordered_map<int,int> ump2;
        for( auto it : ump ){
            if( ump2[ it.second ] == 1 )    return false;
            ump2[ it.second ] = 1;
        }
        return true;
    }
};