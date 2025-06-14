class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int i = 0, n = s.size();
        while( i < n && s[i] == '9' )    i++;
        if( i == n )    return num;
        char c = s[i];
        string maxi = s;
        for( i; i < n; i++ ){
            if( maxi[i] == c )   maxi[i] = '9';
        }
        string minn = s;
        c = minn[0];
        for( int i = 0; i < n; i++ ){
            if( minn[i] == c )  minn[i] = '0';
        }
        return ( stoi(maxi) - stoi(minn) );
    }
};