class Solution {
public:
    void getPrimes(int n, unordered_set<int>& s){
        vector<bool> arr(n+1, true);
        arr[1] = false;
        for( int i = 2; i <= n; i++ ){
            for( int j = i*2; j <= n; j += i ){
                arr[j] = false;
            }
        }
        for( int i = 2; i <= n; i++ )   if( arr[i] )    s.insert(i);
    }

    int getSetBitsCount( int n ){
        int count = 0;
        while(n){
            if( n & 1 ) count++;
            n /= 2;
        }
        return count;
    }

    int countPrimeSetBits(int left, int right) {
        int bits_count = 0, copy = right;
        while( copy ){
            copy /= 2;
            bits_count++;
        }
        int ans = 0;
        unordered_set<int> s;
        getPrimes( bits_count, s );
        for( int i = left; i <= right; i++ ){
            int count = getSetBitsCount(i);
            if( s.count( count ) )  ans++;
        }
        return ans;
    }
};