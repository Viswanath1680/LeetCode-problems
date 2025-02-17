class Solution {
public:
    int backtrack(vector<int>& freq){
        int ways = 0;
        for( int i = 0; i < 26; i++ ){
            if( freq[i] ){
                freq[i]--;
                ways += 1 + backtrack(freq);
                freq[i]++;
            }
        }
        return ways;
    }

    int numTilePossibilities(string tiles) {
        vector<int>freq(26, 0);
        for( auto it : tiles ){
            freq[ it - 'A' ]++;
        }
        return backtrack(freq);
    }
};