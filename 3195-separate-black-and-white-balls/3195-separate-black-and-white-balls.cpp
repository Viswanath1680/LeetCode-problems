// Every 1 in the string s should be swapped with every 0 on its right side.
using ll = long long;
class Solution {
public:
    long long minimumSteps(string s) {
        ll ans = 0, zero_count = 0;
        for( int i = s.size()-1; i >= 0; i-- ){
            if( s[i] == '0' )   zero_count++;
            else    ans += zero_count;
        }
        return ans;
    }
};