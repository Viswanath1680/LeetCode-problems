class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int MOD = 1e9 + 7;
        horizontalCuts.insert( horizontalCuts.begin(), 0 );
        horizontalCuts.emplace_back( h );
        verticalCuts.insert( verticalCuts.begin(), 0 );
        verticalCuts.emplace_back( w );
        int max1 = 0, max2 = 0;
        for( int i = 1; i < horizontalCuts.size(); i++ )
            max1 = max( max1, horizontalCuts[i] - horizontalCuts[i-1] );
        
        for( int i = 1; i < verticalCuts.size(); i++ )
            max2 = max( max2, verticalCuts[i] - verticalCuts[i-1] );
        
        return ( 1LL * max1 * max2 ) % MOD;
    }
};