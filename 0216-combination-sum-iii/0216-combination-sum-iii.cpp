class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int low = k, high = k*9;
        if( n < low || n > high )   return ans;

        vector<int> arr(9, 1);
        for( int i = 1; i < 9; i++ )    arr[i] += arr[i-1];
        vector<int>temp;

        auto recursive = [&](auto& self, int i, int total) -> void {
            if( temp.size() > k )   return;
            if( total == n ){
                if( temp.size() == k ) ans.emplace_back(temp);
                return;
            }
            if( i == 9 || total > n )  return;
            // pick arr[i]
            temp.emplace_back(arr[i]);
            self(self, i+1, total+arr[i]);
            temp.pop_back();

            // don't pick arr[i]
            self(self, i+1, total);
        };

        recursive(recursive, 0, 0);

        return ans;
    }
};