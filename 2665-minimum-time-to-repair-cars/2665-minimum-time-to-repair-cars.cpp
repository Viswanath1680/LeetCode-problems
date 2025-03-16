class Solution {
public:
    bool isPossible(long long time, vector<int>&ranks, int cars){
        long long count = 0;
        for( auto it : ranks ){
            count += sqrt( time / it );
        }
        return (count >= cars * 1LL);
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0;
        long long r = *max_element(ranks.begin(), ranks.end()) * 1LL;
        r *= 1LL * cars * cars;
        long long ans;
        while( l <= r ){
            long long mid = l + (r-l)/2;
            if(  isPossible(mid, ranks, cars)){
                ans = mid;
                r = mid - 1;
            }
            else    l = mid + 1;
        }
        return ans;
    }
};