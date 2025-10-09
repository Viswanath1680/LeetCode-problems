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
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vll prevTimeArray(n, 0);
        prevTimeArray[0] = mana[0] * skill[0];
        for( int i = 1; i < n; i++ )    prevTimeArray[i] += prevTimeArray[i-1] + mana[0] * skill[i];
        // for( auto& it : prevTimeArray ) cout << it << " ";
        // cout << "\n";
        for( int j = 1; j < m; j++ ){
            ll minimumStartingTime = prevTimeArray[0], product = 0;
            for( int i = 1; i < n; i++ ){
                product += mana[j] * skill[i-1];
                minimumStartingTime = max( minimumStartingTime, prevTimeArray[i] - product );
            }
            vll currentTimeArray(n, 0);
            currentTimeArray[0] =  minimumStartingTime + mana[j] * skill[0];
            for( int i = 1; i < n; i++ )    currentTimeArray[i] += currentTimeArray[i-1] + skill[i] * mana[j];
            prevTimeArray = currentTimeArray;
            // for( auto& it : prevTimeArray ) cout << it << " ";
            // cout << "\n";
        }
        return prevTimeArray[n-1];
    }
};