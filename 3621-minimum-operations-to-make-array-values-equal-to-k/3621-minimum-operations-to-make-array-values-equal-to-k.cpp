class Solution {
public:
    int minOperations(vector<int>& arr, int k) {
        for( auto it : arr )    if( it < k )    return -1;
        unordered_map<int, int> ump;
        for( auto it : arr )
            if( it != k )   ump[it]++;
        return ump.size();
    }
};