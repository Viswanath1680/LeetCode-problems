class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for( auto it : rolls ) sum += it;
        int target = mean * ( n + rolls.size() ) - sum;
        vector<int> temp;
        if( target < n || target > n * 6 )  return temp;
        cout << target / n << endl;
        vector<int> ans(n, target/n );
        int i = 0, k = target % n;
        while( k-- )  ans[i++] += 1;
        return ans;        
    }
};