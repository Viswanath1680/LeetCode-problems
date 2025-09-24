using ll = long long;

class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if( num == 0 )  return "0";
        ll numerator = num, denominator = den;
        bool isNegative = false;
        if( numerator < 0 ){
            numerator = llabs(numerator);
            isNegative = !isNegative;
        }
        if( denominator < 0 ){
            denominator = llabs(denominator);
            isNegative = !isNegative;
        }
        string ans = (isNegative == true) ? "-" : "";
        ans += to_string( numerator / denominator );
        ll rem = numerator % denominator;
        if( rem == 0 )  return ans;
        ans += '.';
        ll len = ans.size();
        unordered_map<ll, ll> ump; // {remainder, index}
        while( rem ){
            rem *= 10;
            if( ump.count(rem) ){
                // cout << ump[rem] << "\n";
                ans.insert(ump[rem] + 1, 1, '(');
                ans += ')';
                break;
            }
            ans += to_string( rem / denominator );
            ump[rem] = len - 1;
            rem = rem % denominator;
            len++;
        }
        return ans;
    }
};