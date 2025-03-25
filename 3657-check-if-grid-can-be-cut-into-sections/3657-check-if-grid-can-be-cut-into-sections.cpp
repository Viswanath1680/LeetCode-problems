class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> answer;
        int n = intervals.size();
        for( int i = 0; i < n; i++ ){
            vector<int>temp(2);
            temp[0] = intervals[i][0];
            int maxi = intervals[i][1];
            while( i < n-1 && maxi > intervals[i+1][0] ){
                i++;
                maxi = max(maxi, intervals[i][1]);
            }
            temp[1] = maxi;
            answer.emplace_back(temp);
        }
        return answer;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int size = rectangles.size();
        vector<vector<int>> x_intervals, y_intervals;
        for( auto v : rectangles ){
            x_intervals.push_back({v[0], v[2]});
            y_intervals.push_back({v[1], v[3]});
        }
        x_intervals = mergeIntervals(x_intervals);
        y_intervals = mergeIntervals(y_intervals);
        if( (x_intervals.size() >= 3) || (y_intervals.size() >= 3) )    return true;
        return false;
    }
};