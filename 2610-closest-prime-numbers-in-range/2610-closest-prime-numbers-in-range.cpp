class Solution {
public:
    vector<bool> SieveofEratosthenes(int n){
        vector<bool> is_prime(n+1, true);
        is_prime[1] = false;

        for( int i = 2; i <= sqrt(n); i++ ){
            if( is_prime[i] ){
                for( int j = 2*i; j <= n; j += i )  is_prime[j] = false;
            }
        }
        return is_prime;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> is_prime = SieveofEratosthenes(right);
        vector<int> primes;
        for( int i = left; i <= right; i++ )    if( is_prime[i] )   primes.emplace_back(i);
        if( primes.size() < 2 ) return {-1, -1};
        int min_diff = INT_MAX;
        int ind = 0;
        for( int i = 0; i < primes.size()-1; i++ ){
            cout << primes[i] << " ";
            int diff = ( primes[i+1] - primes[i] );
            if( min_diff > diff ){
                min_diff = diff;
                ind = i;
            }
        }
        cout << primes.back();
        return { primes[ind], primes[ind+1] };
    }
};