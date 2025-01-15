class Solution {
public:
    int divisorsSum(int n){
        int sq = sqrt(n), sum = 0;
        for( int i = 1; i <= sq; i++ ){
            if( n % i == 0 ){
                sum += i;
                if( i != n/i && i != 1)   sum += n/i;
            }
        }
        return sum;
    }

    bool checkPerfectNumber(int num) {
        if( num == 1 )  return false;
        return (divisorsSum(num) == num);
    }
};