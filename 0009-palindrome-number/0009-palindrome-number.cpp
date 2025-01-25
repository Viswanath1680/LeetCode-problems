class Solution {
public:
    long long rev(int x){
        long long n = 0;
        while( x ){
            n = n * 10 + ( x%10 );
            x /= 10;
        }
        return n;
    }

    bool isPalindrome(int x) {
        if( x < 0 ) return false;
        return (rev(x) == x);
    }
};