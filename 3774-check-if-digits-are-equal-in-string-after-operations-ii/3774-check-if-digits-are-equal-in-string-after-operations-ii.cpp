class Solution {
private:
    // Precomputed factorials and their modular multiplicative inverses for mod 2 and mod 5
    static const int MAX_N = 1e5; // Adjust based on constraints
    vector<int> fact2, inv2;
    vector<int> fact5, inv5;
    
    // Fast modular exponentiation
    int modPow(int base, int exp, int mod) {
        int result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1)
                result = (1LL * result * base) % mod;
            base = (1LL * base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    
    // Initialize factorial arrays and their inverses
    void precompute() {
        // For mod 2
        fact2.resize(2);
        inv2.resize(2);
        fact2[0] = 1;
        fact2[1] = 1;
        inv2[1] = 1;
        
        // For mod 5
        fact5.resize(5);
        inv5.resize(5);
        fact5[0] = 1;
        for(int i = 1; i < 5; i++) {
            fact5[i] = (1LL * fact5[i-1] * i) % 5;
        }
        for(int i = 0; i < 5; i++) {
            inv5[i] = modPow(fact5[i], 3, 5); // Using Fermat's little theorem
        }
    }
    
    // Efficient nCr calculation for small prime modulus
    int nCrModPrime(int n, int r, int p, const vector<int>& fact, const vector<int>& inv) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (p == 2) return n & 1 && r & 1 ? 1 : 0;
        
        // For mod 5, use Lucas Theorem directly with small numbers
        n %= p;
        r %= p;
        if (r > n) return 0;
        return (1LL * fact[n] * inv[r] % p * inv[n-r]) % p;
    }
    
    // Optimized Lucas Theorem
    int lucas(int n, int r, int p, const vector<int>& fact, const vector<int>& inv) {
        if (r == 0) return 1;
        if (r > n) return 0;
        
        int result = 1;
        while (n > 0 && r > 0) {
            int ni = n % p;
            int ri = r % p;
            if (ri > ni) return 0;
            result = (1LL * result * nCrModPrime(ni, ri, p, fact, inv)) % p;
            n /= p;
            r /= p;
        }
        return result;
    }

public:
    Solution() {
        precompute();
    }
    
    vector<int> Pascal(int n) {
        vector<int> ans;
        ans.reserve(n);
        
        for(int i = 0; i < n; i++) {
            if(i > (n-1)/2) {
                ans.push_back(ans[n-1-i]);
            } else {
                int n_minus_1 = n - 1;
                // Calculate mod 2 and mod 5 directly
                int mod2 = lucas(n_minus_1, i, 2, fact2, inv2);
                int mod5 = lucas(n_minus_1, i, 5, fact5, inv5);
                
                // Combine using precomputed CRT values
                int result = (mod2 * 5 * (-1) + mod5 * 2 * 3) % 10;
                result = (result + 10) % 10;
                
                ans.push_back(result);
            }
        }
        return ans;
    }
    
    bool hasSameDigits(string s) {
        int n = s.length();
        vector<int> coeff = Pascal(n-1);
        
        int n1 = 0, n2 = 0;
        for(int i = 0; i < n-1; i++) {
            n1 = (n1 + coeff[i] * (s[i] - '0')) % 10;
            n2 = (n2 + coeff[i] * (s[i+1] - '0')) % 10;
        }
        return n1 == n2;
    }
};