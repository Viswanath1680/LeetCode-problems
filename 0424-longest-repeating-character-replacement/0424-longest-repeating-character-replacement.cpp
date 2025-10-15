// Window can have atmost k chars which are not equal to most frequent character, for the answer to be maximum. Our goal is to maximise the len of the window.

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, len = 0, maxi = 0, ans = 0;
        // len is length of the window, which is (r-l+1)
        unordered_map<char, int> mp;
        while( r < s.length() ){
            mp[ s[r] ]++;
            len++;
            maxi = max(maxi, mp[ s[r] ]);   // most frequent char in the window
            while( len - maxi > k ){
                mp[ s[l] ]--;
                if( mp[s[l]] == 0 ) mp.erase( s[l] );
                l++;
                len--;
                int temp_max = INT_MIN;
                for( auto it : mp )
                    temp_max = max( temp_max, it.second );
                maxi = temp_max;
            }
            ans = max( ans, len );
            r++;
        }   
        return ans;
    }
};