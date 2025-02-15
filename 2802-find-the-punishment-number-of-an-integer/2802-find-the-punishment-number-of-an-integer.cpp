class Solution {
public:
    bool isValidPartition(int square, int target) {
        string num_str = to_string(square);
        int n = num_str.length();
        int total_partitions = 1 << (n - 1); // 2^(n-1) partitions
        
        for (int mask = 0; mask < total_partitions; ++mask) {
            int sum = 0;
            int start = 0;
            
            // substrings based on the mask
            for (int i = 0; i < n - 1; ++i) {
                if (mask & (1 << i)) { // Partition at position i
                    sum += stoi(num_str.substr(start, i - start + 1));
                    start = i + 1;
                }
            }
            sum += stoi(num_str.substr(start));
            
            if (sum == target) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for( int i = 1; i <= n; i++ ){
            if( isValidPartition(i*i, i) )  ans += i*i;
        }
        return ans;
    }
};