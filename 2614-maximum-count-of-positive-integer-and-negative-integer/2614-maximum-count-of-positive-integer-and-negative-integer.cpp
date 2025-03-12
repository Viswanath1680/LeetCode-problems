class Solution {
public:
    int maximumCount(vector<int>& arr) {
        int low = lower_bound(arr.begin(), arr.end(), 0) - arr.begin();
        int up = upper_bound(arr.begin(), arr.end(), 0) - arr.begin();
        return max( low , (int)arr.size() - up );
    }
};