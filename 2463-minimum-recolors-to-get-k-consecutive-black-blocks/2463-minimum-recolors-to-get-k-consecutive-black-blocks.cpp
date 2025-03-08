class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.length();
        int temp = 0, maxBlack;
        for( int i = 0; i < k; i++ )    if( s[i] == 'B' )   temp++;
        if( temp == k ) return 0;
        maxBlack = temp;
        for( int i = k; i < n; i++ ){
            if( s[i-k] == 'B' ) temp --;
            if( s[i] == 'B' )   temp++;
            maxBlack = max(maxBlack, temp);
        }
        return k - maxBlack;
    }
};