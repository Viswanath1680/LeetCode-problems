class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), l = 0, r = 0, ans = 0;
        map<char, int> mp;
        while( r < n ){
            if( mp.find( s[r] ) == mp.end() ){   
                mp[s[r]]++;
                ans = max( ans, r-l+1 );
                r++;
            }
            else{
                mp.erase( s[l] );
                l++;
            }
        }
        return ans;
    }
};