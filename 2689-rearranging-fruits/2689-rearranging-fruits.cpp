using vvi = vector<vector<int>>;
using vi = vector<int>;
using pi = pair<int, int>;
using vb = vector<bool>;
using vs = vector<string>;
using vvs = vector<vector<string>>;
using ll = long long;

class Solution {
public:
    ll minCost(vi& basket1, vi& basket2) {
        unordered_map<int, ll> ump;
        for( auto it : basket1 )    ump[it]++;
        for( auto it : basket2 )    ump[it]--;
        for( auto [key, freq] : ump )   if( freq & 1 )  return -1;
        int minimum_val = INT_MAX;
        vector<pi> positives, negatives;
        for( auto pair : ump ){
            auto [key, freq] = pair;
            minimum_val = min(minimum_val, key);
            if( freq == 0 )  continue;
            if( freq > 0 )   positives.push_back(pair);
            else    negatives.push_back(pair);
        }
        sort(positives.begin(),positives.end());
        sort(negatives.begin(),negatives.end());

        ll ans = 0;
        
        int i = 0, j = negatives.size()-1;
        while( i < positives.size() && j >= 0 ){
            auto& [firstMin, freq1] = positives[i];
            auto& [secondMin, freq2] = negatives[j];
            ans += min( (ll)firstMin, min((ll)secondMin, 2LL * minimum_val) );
            freq1 -= 2;
            freq2 += 2;
            if( freq1 == 0 )    i++;
            if( freq2 == 0 )    j--;
        }
        return ans;
    }
};