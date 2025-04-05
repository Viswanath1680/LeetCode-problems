class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int p_size = 1 << n;
        for( int i = 0; i < p_size; i++ ){
            int xor_sum = 0;
            for( int j = 0; j < n; j++ ){
                if( i & (1<<j) )    xor_sum ^= arr[j];
            }
            ans += xor_sum;
        }
        return ans;
    }
}; 