class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if( s1.length() > s2.length() )     return false;
        vector<int> v1( 26, 0 ), v2( 26, 0 );
        for( auto it : s1 ) v1[ it-'a' ]++;
        int i = 0, j = s1.length()-1;
        for( int p = i; p <= j; p++)    v2[ s2[p] - 'a' ]++;
        if( v1 == v2 )  return true;
        for( int p = j+1; p < s2.length(); p++ ){
            v2[ s2[p - s1.length()] - 'a' ]--;
            v2[ s2[p] - 'a' ]++;
            if( v1 == v2 )  return true;
        }
        return false;
    }
};