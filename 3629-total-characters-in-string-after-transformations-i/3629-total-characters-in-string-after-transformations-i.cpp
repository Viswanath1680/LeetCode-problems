class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9 + 7;
        vector<int> freq(26, 0);
        for( auto it : s )  freq[ it-'a' ]++;
        while(t--){
            int temp = freq[25];
            for( int i = 25; i >= 1; i-- )    freq[i] = freq[i-1];
            freq[0] = temp;
            freq[1] = (freq[1] + temp ) % mod;
        }
        int ans = 0;
        for( int i = 0; i < 26; i++ )   ans = ( ans + freq[i] ) % mod;
        return ans;
    }
};