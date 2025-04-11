class Solution {
public:
    // 0 1 2 3
    bool isSymmetric( string s ){
        int n = s.length();
        if( n & 1 ) return false;
        int sum1 = 0, sum2 = 0;
        for( int i = 0; i < n/2; i++ )    sum1 += s[i] - '0';
        for( int i = n/2; i < n; i++ )  sum2 += s[i] - '0';
        return (sum1 == sum2);
    }

    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for( int i = low; i <= high; i++ ){
            string s = to_string(i);
            if( isSymmetric(s) )    ans++;
        }
        return ans;
    }
};