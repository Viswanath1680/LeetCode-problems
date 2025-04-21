class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> prefix(n, 0);
        prefix[0] = differences[0];
        for( int i = 1; i < n; i++ )    prefix[i] = prefix[i-1] +(long long)differences[i];
        //  example case -> 1 -2 2
        //  (least number in differences+ hidden[0]) should be >= lower
        //  and ( max number in differences + hidden[0] should be <= upper)
        long long min_val = (long long)lower, max_val = (long long)upper;   // min and max vals for hidden[0]
        for( auto v : prefix ){
            if( v + min_val < lower ){
                long long diff = lower - (v+ min_val);
                min_val += diff;
            }
            if( v + max_val > upper ){
                long long diff = ( v + max_val )  - upper;
                max_val -= diff;
            }
        }
        return ( max_val < min_val ) ? 0 : (max_val - min_val + 1);
        if( (max_val-min_val+1) < 0 )   return 0;
        return (max_val-min_val+1);
        return (max_val - min_val+1) < 0 ? 0 : max_val - min_val+1;
    }
};