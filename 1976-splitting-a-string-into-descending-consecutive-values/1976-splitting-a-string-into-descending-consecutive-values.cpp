// Neetcode
using ull = unsigned long long;
class Solution {
public:
    bool splitString(string s) {
        int n = s.length();

        auto dfs = [&](auto& self, ull prev_val, int i) -> bool{
            if( i == n )    return true;
            string temp = "";
            for( i; i < n; i++ ){
                temp += s[i];
                ull val = stoull(temp);   // same as stoi function, but for ull
                if( val == prev_val-1 ){
                    bool isTrue = self(self, val, i+1);
                    if( isTrue )    return true;
                }
            }
            return false;
        };

        string temp;
        for( int i = 0; i < n-1; i++ ){
            temp += s[i];
            ull val = stoull(temp);   // same as stoi function, but for ull
            if( val == 0 )  continue;
            if( dfs(dfs, val, i+1) )    return true;
        }
        return false;
    }
};