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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(),potions.end());
        vi pairs(n);
        for( int i = 0; i < n; i++ ){
            int spell_strength = spells[i];
            ll quotient = ( success / spell_strength );
            if( success % spell_strength )  quotient++;
            // we need atleast quotient potions[j].
            auto ind = lower_bound( potions.begin(), potions.end(), quotient );
            // cout << quotient << " " << ind << "\n";
            pairs[i] =  potions.end() - ind;
        }
        return pairs;
    }
};