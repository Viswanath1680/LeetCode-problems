class Solution {
public:
    string getSmallestString(string s) {
        for( int i = 1; i < s.length(); i++ ){
            int parity1 = ( s[i-1] - '0' ) % 2;
            int parity2 = ( s[i] - '0' )%2;
            if( s[i-1] > s[i] && parity1 == parity2 ){
                swap( s[i-1], s[i] );
                break;
            }
        }
        return s;
    }
};