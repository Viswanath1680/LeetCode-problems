class Solution {
public:
    long long calculateHours( vector<int>& piles, int k ){
        long long ans = 0;
        for( auto it : piles ){
            ans += it/k;
            if( it % k )    ans++;
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element( piles.begin(), piles.end() );
        int ans = r;
        while( l <= r ){
            int mid = l + (r-l)/2;
            long long time = calculateHours( piles, mid );
            if( time > h )
                l = mid + 1;
            else{
                ans = min( ans, mid );
                r = mid - 1;
            }
        }
        return ans;
    }
};