// https://www.youtube.com/watch?v=yRRDVX3sO8U
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long count = 0;
        while( k != 1 ){
            long long power = ceil( log2(k) ) - 1;
            long long len = pow(2, power);
            k = k - len;
            if( operations[power] ) count++;
        }
        count = count % 26;
        return ( 'a' + count );
    }
};