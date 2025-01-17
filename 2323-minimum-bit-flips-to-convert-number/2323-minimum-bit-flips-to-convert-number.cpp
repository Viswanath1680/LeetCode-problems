class Solution {
public:
    int minBitFlips(int start, int goal) {
        int target = start ^ goal;
        int ans = 0;
        while( target ){
            if( target % 2 )    ans++;
            target >>= 1;
        }
        return ans;
    }
};