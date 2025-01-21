class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        for( auto it : t )  mp[it]++;
        int l = 0, r = 0, start = 0, count = mp.size(), len = s.length()+1;
        if( s.length() < t.length() )   return "";
        while( r < s.length() ){
            if( mp.find( s[r] ) != mp.end() ){
                mp[s[r]]--;
                if( mp[ s[r] ] == 0 )   count--;
            }
            if( count == 0 ){
                while( count == 0 ){
                    if( mp.find( s[l] ) != mp.end() ){
                        mp[s[l]]++;
                        if( mp[s[l]] == 1 ){
                            count++;
                            if( r - l + 1 < len ){
                                len = r - l + 1;
                                start = l;
                            }
                        }
                    }
                    l++;
                }
            }
            r++;
        }
        if( len == s.length()+1 ) return "";
        return s.substr(start, len);
    }
};