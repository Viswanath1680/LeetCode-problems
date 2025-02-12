class Solution {
public:
    int digitsSum(int n){
        int ans = 0;
        while( n ){
            ans += n%10;
            n /= 10;
        }
        return ans;
    }

    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> ump;
        for( auto it : arr ){
            int sum = digitsSum(it);
            ump[sum].emplace_back(it);
        }
        for( auto & it : ump ){
            sort( it.second.begin(), it.second.end(), greater<int>());
        }
        vector<int>ans;
        int sum = -1;
        for( auto it : ump ){
            if( it.second.size() > 1 ){
                int temp = (it.second[0] + it.second[1]); 
                sum = max(sum, temp);
            }
        }
        return sum;
    }
};