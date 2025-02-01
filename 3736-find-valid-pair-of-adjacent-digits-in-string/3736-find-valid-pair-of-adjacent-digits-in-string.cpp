class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> ump;
        for( auto it : s )    ump[ it ]++;

        string ans = "";
        int n = s.length();
        for( int i = 0; i < n-1; i++ ){
            if( s[i] == s[i+1] )   continue;
            int a = ump[ s[i] ];
            int b = ump[ s[i+1] ];
            if( (s[i] - '0') == a && (s[i+1] - '0') == b ){
                ans += s[i];
                ans += s[i+1];
                break;
            }
        }
        return ans;
    }
};