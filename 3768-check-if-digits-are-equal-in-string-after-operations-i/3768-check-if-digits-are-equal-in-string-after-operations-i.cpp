class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        while( n > 2 ){
            string temp = "";
            for( int i = 0; i < n-1; i++ ){
                int sum = ( s[i] - '0' + s[i+1] - '0' ) % 10;
                temp += sum;
            }
            s = temp;
            n = s.length();
        }
        return ( s[0] == s[1] );
    }
};