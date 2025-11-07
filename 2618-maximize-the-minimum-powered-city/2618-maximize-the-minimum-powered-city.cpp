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
    bool check(ll& target, vll& currPower, int r, int k){
        // iterate left to right, look forward at all times.
        // so, put the station at i + r at all times, if current i position has a val that's less than our target.
        cout << target << "\n";
        int n = currPower.size();
        vll zeroesSum(n+1, 0);
        ll prefixSum = 0;
        for(int i = 0; i < n; i++) {
            prefixSum += zeroesSum[i];
            if(currPower[i] + prefixSum < target) {
                int diff = target - currPower[i] - prefixSum;
                if(diff > k) return false;
                k -= diff;
                // plant diff many power stations at i+r
                zeroesSum[i] += diff;
                int rightmost = min(n - 1, i + 2*r);
                zeroesSum[ rightmost + 1 ] -= diff;
                prefixSum += diff;
            }
        }
        return true;
    }

    ll maxPower(vector<int>& stations, int r, int k) {
        ll runningSum = 0;
        vector<ll> currPower(stations.size(), 0);
        int prevl = 0, prevh = r;
        for( int i = 0; i < stations.size(); i++ ){
            int l = max(0, i-r), h = min((int)stations.size()-1, i+r);
            if (i == 0) for (int j = l; j <= h; j++) runningSum += stations[j];
            else {
                if(prevl != l) runningSum -= stations[prevl];
                if(prevh != h) runningSum += stations[h];
            }
            currPower[i] = runningSum;
            prevl = l, prevh = h;
        }

        // for(auto& x : currPower) cout << x << " ";

        ll low = 0, high = *min_element(currPower.begin(), currPower.end()) + k;
        // cout << high << "\n";
        ll ans = 0;
        while( low <= high ){
            ll mid = low + ( high - low )/2;
            auto isValid = check(mid, currPower, r, k);
            if( isValid ){
                low = mid + 1;
                ans = max(ans, mid);
            }
            else    high = mid - 1;
        }
        return ans;
    }
};