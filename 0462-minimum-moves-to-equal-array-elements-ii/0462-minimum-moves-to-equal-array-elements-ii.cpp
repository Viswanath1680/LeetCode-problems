class Solution {
public:
    int minMoves2(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int med = arr[n/2];
        int ans = 0;
        for( auto it : arr )    ans += abs(med-it);
        return ans;
    }
};