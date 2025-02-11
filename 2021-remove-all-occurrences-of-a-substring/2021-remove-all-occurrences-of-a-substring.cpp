class Solution {
public:
    bool isequal( string s, string part ){
        int n = s.length(), k = part.length();
        if( n < k ) return false;
        // last k chars from n-1 -> n-k to n-1
        string temp = s.substr(n-k, k);
        return ( temp == part );
    }

    string removeOccurrences(string s, string part) {
        int n = s.length(), k = part.length();
        if( n < k ) return s;
        string ans = "";
        // base case
        for( int i = 0; i < k; i++ )    ans += s[i];
        if( isequal(ans, part) ){
            int d = k;
            while(d--)  ans.pop_back();
        }
        // now length is >= k
        for( int i = k; i < n; i++ ){
            ans += s[i];
            if( ans.length() >= k ){
                if( isequal(ans, part) ){
                    int d = k;
                    while(d--)  ans.pop_back();
                }
            }
        }
        return ans;
    }
};