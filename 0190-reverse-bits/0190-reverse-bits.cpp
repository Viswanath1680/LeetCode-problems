class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, i = 1 << 31;
        while( n ){
            ans += i * ( n & 1 );
            i >>= 1;
            n >>= 1;
        }
        return ans;
    }
};