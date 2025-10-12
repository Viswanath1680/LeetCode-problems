// slow-fast ptr type, since given that cycles are possible
using ll = long long;
class Solution {
public:
    ll digitSum(int n){
        ll sum = 0;
        while( n ){
            int rem = n % 10;
            sum += rem * rem;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        if( n == 1 )    return true;
        ll slow = digitSum(n), fast = digitSum( digitSum(n) );
        if( slow == 1 ) return true;
        while( fast != 1 ){
            slow = digitSum(slow);
            fast = digitSum( digitSum(fast) );
            if( fast == 1 ) return true;
            if( slow == fast )  return false;
        }
        return true;
    }
};