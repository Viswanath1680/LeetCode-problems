class Solution {
public:
    int recursion(string s, int i, int n, long long &sum, int sign){
        if( i == n )    return sign * sum;
        if( s[i] < '0' || s[i] > '9' )  return sign * sum;
        int k = s[i] - '0';
        sum = sum * 10 + k;
        long long signedSum = sign * sum;
        if (signedSum <= INT_MIN) return INT_MIN;
        if (signedSum >= INT_MAX) return INT_MAX;
        return recursion(s, i+1, n, sum, sign );
    }

    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        long long sum = 0;
        while( i < n && s[i] == ' ' )   i++;
        int sign = 1;
        if( s[i] == '-' )   {
            sign = -1;
            i++;
        }
        else if( s[i] == '+' )   i++;
        return recursion(s, i, n, sum, sign);
    }
};