class Solution {
public:
    bool checkIfSubArray(vector<int>& freq, vector<int>& temp_freq){
        for( int i = 0; i < 26; i++ ){
            if( temp_freq[i] > 0 ){
                if( temp_freq[i] != freq[i] )   return false;
            }
        }
        return true;
    }

    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> freq(26, 0), ans;
        for( auto it : s )  freq[it-'a']++;

        int i = 0, prev_i = 0;
        for( i = 0; i < n; ){
            vector<int> temp_freq(26, 0);
            char c = s[i];
            temp_freq[ c-'a' ]++;
            i++;
            while( i < n && checkIfSubArray(freq, temp_freq) == false ){
                c = s[i];
                temp_freq[ c-'a' ]++;
                i++;
            }
            if( checkIfSubArray(freq, temp_freq) ){
                ans.push_back( i-prev_i );
                prev_i = i;
            }
        }
        return ans;
    }
};