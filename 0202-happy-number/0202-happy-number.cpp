class Solution {
public:
    int nextNum( int n ){
        int ans = 0;
        while( n ){
            ans += (n%10) * (n%10);
            n /= 10;
        }
        return ans;
    }

    bool isHappy(int n) {
        if( n == 1 )    return true;
        int slow , fast;
        slow = nextNum(n);
        fast = nextNum( n );
        fast = nextNum( fast );
        while( slow != fast && slow != 1 && fast != 1 ){
            slow = nextNum(slow);
            fast = nextNum( fast );
            fast = nextNum( fast );
        }
        if( slow == 1 || fast == 1 )    return true;
        return false;
    }
};