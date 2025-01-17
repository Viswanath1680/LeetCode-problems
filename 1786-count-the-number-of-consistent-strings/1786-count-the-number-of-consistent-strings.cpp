class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> target(26, false);
        for( auto it : allowed )   target[ it - 'a' ] = true;

        int ans = 0;
        for( string s : words ){
            vector<bool> temp(26, false);
            for( auto it : s)   temp[ it - 'a' ] = true;
            bool flag = true;
            for( int i = 0; i < 26; i++ ){
                if( target[i] != temp[i] ){
                    if( temp[i] == true ){
                        flag = false;
                        break;
                    }
                }
            }
            if( flag )  ans++;
        }
        return ans;
    }
};