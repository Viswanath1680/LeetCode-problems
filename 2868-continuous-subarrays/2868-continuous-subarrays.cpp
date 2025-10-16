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
    long long continuousSubarrays(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = 0;
        ll ans = 0;
        std::multiset<int> ms;
        while( r < n ){
            ms.insert( arr[r] );
            int maximum_el = *ms.rbegin(), minimum_el = *ms.begin();
            while( maximum_el - minimum_el > 2 ){
                ms.erase( ms.find(arr[l]) );
                l++;
                maximum_el = *ms.rbegin(), minimum_el = *ms.begin();
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
};