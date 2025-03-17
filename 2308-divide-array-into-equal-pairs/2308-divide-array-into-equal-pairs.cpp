class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> ump;
        for( auto it : nums )   ump[it]++;
        for( auto it : ump )
            if( it.second & 1 )     return false;
        return true;
    }
};