class Solution {
public:
    vector<int> queryResults(int n, vector<vector<int>>& queries) {
        unordered_map<int, int> ball, color;
        // ball[i] -> i is the index of the ball and ball[i] is the current color of the ball
        // color[i] -> number of balls with color[i] as their color. 
        vector<int>ans;
        // arr[0] -> ball number
        // arr[1] -> ball color
        for( auto arr : queries ){
            int paint = arr[1];
            // first time painting the ball
            if( ball.find( arr[0] ) == ball.end() ){
                ball[ arr[0] ] = paint;
                color[ arr[1] ]++;
                ans.emplace_back( color.size() );
            }
            // repainting the ball
            else{
                int prev_paint = ball[ arr[0] ];
                color[ prev_paint ]--;
                if( color[prev_paint] == 0 )    color.erase( prev_paint );
                ball[ arr[0] ] = paint;
                color[ arr[1] ]++;
                ans.emplace_back(color.size());
            }
        }
        return ans;
    }
};