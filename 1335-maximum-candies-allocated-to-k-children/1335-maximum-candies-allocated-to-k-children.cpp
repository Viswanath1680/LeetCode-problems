// Same as Koko eating bananas question https://leetcode.com/problems/koko-eating-bananas/description/
class Solution {
public:
    // dividing every pile into mid number of chunks
    bool isSatisfying(vector<int>arr, long long k, long long mid){
        long long piles = 0;
        for( auto it : arr )    {
            piles += it / mid;
            if( piles >= k )    return true;
        }
        if( piles < k ) return false;
        return true;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for( auto it : candies )    sum += 1LL * it;
        if( sum < k )   return 0;

        long long l = 1, r = *max_element(candies.begin(), candies.end());
        long long ans;
        while( l <= r ){
            long long mid = l + (r-l)/2;
            bool val = isSatisfying(candies, k, mid);
            if( val ){
                ans = mid;
                l = mid+1;
            }
            else    r = mid-1;
        }
        return ans;
    }
};