class Solution {
public:
    // Bit manipulation, Iterate over all 31 bits. For ith bit, check how many integers have
    // ith bit as 1-> 3x + 1 if the target element has ith bit else 3x. Act accordingly
    int singleNumber(vector<int>& arr) {
        int ans = 0;
        for( int i = 0; i <= 31; i++ ){
            int count = 0;
            int num = 1 << i;
            for( auto it : arr )    if( it & num )  count++;
            if( count % 3 ) ans += (1 <<  i);
        }
        return ans;
    }
};