class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if( nums.size() <= 1 )  return nums.size();
        map<int,bool> mp;
        for( auto it : nums )   mp[ it ] = true;
        int ans = 1, maxi = 0;
        auto i = mp.begin();
        while( i != mp.end() ){
            if( next(i) != mp.end() && ( (i->first + 1) == next(i)->first) ){
                ans++;
            }
            else{
                maxi = max( maxi, ans );
                ans = 1;
            }
            i++;
        }
        maxi = max( maxi , ans );
        return maxi;
    }
};