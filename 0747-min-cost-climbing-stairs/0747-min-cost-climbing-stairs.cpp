class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int one_back = 0, two_back = 0, curr;
        for( int i = 2; i <= n; i++ ){
            curr = min( one_back + cost[i-1], two_back + cost[i-2] );
            two_back = one_back;
            one_back = curr;
        }
        return curr;
    }
};