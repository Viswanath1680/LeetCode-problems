class Solution {
public:
    long long nC2( int m ){
        long long n = m;
        long long ans = ( n*(n-1) )/2;
        return ans;
    }

    long long countBadPairs(vector<int>& arr) {
        int n = arr.size();
        int valid = 1;
        unordered_map<int, int> ump;
        for( int i = 0; i < n; i++ ){
            arr[i] -= i;
            ump[arr[i]]++;
        }
        long long ans = nC2(n);
        for( auto it : ump ){
            if( it.second != 1 )    ans -= nC2( it.second );
        }
        return ans;
    }
};