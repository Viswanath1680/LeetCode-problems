class Solution {
public:
// Count and sort frequencies.
// For each freq f, assume it's the minimum allowed.
// Delete smaller ones entirely, trim larger ones to f + k.
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for( auto c : word )    freq[ c-'a' ]++;
        int mini = INT_MAX, maxi = 0;
        for( auto it : freq ){
            if( it == 0 )  continue;
            mini = min(mini, it);
            maxi = max(maxi, it);
        }
        if( maxi - mini <= k )  return 0;
        sort(freq.begin(),freq.end());
        freq.erase(remove(freq.begin(), freq.end(), 0), freq.end());
        int ans = INT_MAX, n = freq.size();
        for( int i = 0; i < n; i++ ){
            int temp_ans = 0;
            int threshold = freq[i];
            for( int j = 0; j < n; j++ ){
                if( freq[j] < threshold )   temp_ans += freq[j];
                else if( freq[j] > threshold + k )  temp_ans += ( freq[j] - threshold - k );
            }
            ans = min(ans, temp_ans);
        }
        return ans;
    }
};