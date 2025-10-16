using vvi = vector<vector<int>>;
using vi = vector<int>;
using vll = vector<long long>;
using pi = pair<int, int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vi p_freq(26, 0);
        for( auto& it : p ) p_freq[ it - 'a' ]++;
        // window size should be same as string p size
        int k = p.size();
        vi freq(26, 0);
        vi ans;
        for( int i = 0; i < s.size(); i++ ){
            freq[ s[i] - 'a' ]++;
            if( i >= k-1 ){
                int low = i - k;
                if( low >= 0 )  freq[ s[low] - 'a' ]--;
                if( freq == p_freq )    ans.emplace_back(low+1);
            }
        }
        return ans;
    }
};