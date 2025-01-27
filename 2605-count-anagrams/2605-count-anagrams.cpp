class Solution {
public:
    unordered_map<int, int> HASH;
    const int MOD = 1e9 + 7;
    
    int power(int a, int b) {
        int res = 1;
        while (b > 0) {
            if (b % 2 == 1)
                res = mulmod(res, a);
            a = mulmod(a,a);
            b /= 2;
        }
        return res;
    }
    
    int modInverse(int a) {
        return power(a, MOD - 2);
    }
    
    int mulmod(int a, int b){
        return (1LL * a * b) % MOD;
    }
    
    int factorial(int n) {
        if (n == 0 || n == 1)
            return 1;
        if (HASH.find(n) != HASH.end())
            return HASH[n];
        HASH[n] = mulmod(n, factorial(n - 1));
        return HASH[n];
    }
    
    int permutations(map<char, int>& mp) {
        int sum = 0;
        for (auto it : mp)
            sum += it.second;
        int product = 1;
        for (auto it : mp)
            product = mulmod(product, factorial(it.second));
        return mulmod(factorial(sum), modInverse(product));
    }
    
    int countAnagrams(string s) {
        int ans = 1;
        for( int i = 0 ; i < s.length(); i++ ){
            map<char, int> temp;
            while( i < s.length() && s[i] != ' ' ){
                temp[s[i]]++;
                i++;
            }
            ans = mulmod(ans, permutations(temp));
        }
        return ans;
    }
};