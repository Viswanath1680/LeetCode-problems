class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0, n = intervals.size();
        int previous = 0, current = 1;
        sort(intervals.begin(), intervals.end());
        for( current = 1; current < n; current++){
            // overlapping case
            if( intervals[previous][1] > intervals[current][0] ){
                ans++;
                if( intervals[previous][1] > intervals[current][1] ){
                    previous = current;
                }
            }
            else    previous = current;
        }
        return ans;
    }
};