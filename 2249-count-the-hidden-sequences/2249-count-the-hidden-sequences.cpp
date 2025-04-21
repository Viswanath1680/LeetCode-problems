class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        // Idea is to calculate prefix sum
        //  example case -> 1 -2 2
        //  (least number in differences+ hidden[0]) should be >= lower
        //  and ( max number in differences + hidden[0] should be <= upper)
        long long min_val = (long long)lower, max_val = (long long)upper;   // min and max vals for hidden[0]
        long long prefix_sum = 0;
        for( auto v : differences ){
            prefix_sum += (long long) v;
            if( prefix_sum + min_val < lower ){
                long long diff = lower - (prefix_sum+ min_val);
                min_val += diff;
            }
            if( prefix_sum + max_val > upper ){
                long long diff = ( prefix_sum + max_val )  - upper;
                max_val -= diff;
            }
        }
        return ( max_val < min_val ) ? 0 : (max_val - min_val + 1);
    }
};