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

// Multiset helps a lot that you think

class Solution {
public:
    int longestSubarray(vector<int>& arr, int limit) {
        int ans = 1, n = arr.size();
        multiset<int> ms;
        int l = 0, r = 0;
        while( r < n ){
            ms.insert(arr[r]);
            int minimum_el = *ms.begin(), maximum_el = *ms.rbegin();
            while( maximum_el - minimum_el > limit ){
                ms.erase(ms.find(arr[l]));  // ms.erase(iterator) erases the element pointed to by the iterator (only one occurrence).
                l++;
                minimum_el = *ms.begin(),
                maximum_el = *ms.rbegin();
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};