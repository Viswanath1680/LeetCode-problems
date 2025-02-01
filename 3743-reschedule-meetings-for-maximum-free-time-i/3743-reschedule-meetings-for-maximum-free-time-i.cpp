class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTimes;
        freeTimes.emplace_back( startTime[0] - 0 );
        int n = startTime.size();
        for( int i = 1; i < n; i++ )    freeTimes.emplace_back( startTime[i] - endTime[i-1] );
        freeTimes.emplace_back( eventTime - endTime[n-1] );

        int ans = 0;
        for( int i = 0; i <= k; i++ )    ans += freeTimes[i];

        int window = ans;
        for( int i = k+1; i < freeTimes.size(); i++ ){
            window -= freeTimes[i-k-1];
            window += freeTimes[i];
            ans = max(ans, window);
        }
        return ans;
    }
};