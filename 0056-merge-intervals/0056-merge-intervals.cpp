bool comparator( vector<int>a, vector<int>b ){
    if( a[0] == b[0] )  return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), comparator);
        vector<vector<int>> answer;
        int n = intervals.size();
        for( int i = 0; i < n; i++ ){
            vector<int>temp(2);
            temp[0] = intervals[i][0];
            int maxi = intervals[i][1];
            while( i < n-1 && maxi >= intervals[i+1][0] ){
                i++;
                maxi = max(maxi, intervals[i][1]);
            }
            temp[1] = maxi;
            answer.emplace_back(temp);
        }
        return answer;
    }
};