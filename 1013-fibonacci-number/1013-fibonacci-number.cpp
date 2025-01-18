class Solution {
public:
    int fib(int n) {
        if( n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else if( n == 2 )
            return 1;
        int one_back = 1;
        int two_back = 1;
        for( int i = 2; i < n ; i++){
            int curr = one_back + two_back;
            two_back = one_back;
            one_back = curr;
        }
        return one_back;
    }
};