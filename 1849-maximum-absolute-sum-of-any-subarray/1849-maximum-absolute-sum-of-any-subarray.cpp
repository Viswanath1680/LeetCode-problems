class Solution {
public:
    int kadane(vector<int> arr){
        int ans = arr[0];
        int temp = arr[0];
        int n = arr.size();
        for(int i = 1; i < n; i++){
            temp = max(temp+arr[i], arr[i]);
            ans = max(ans, temp);
        }
        return ans;
    }

    int maxAbsoluteSum(vector<int>& arr) {
        vector<int>copy = arr;
        for(auto& it : arr) it = -it;
        int ans1 = kadane(arr);
        int ans2 = kadane(copy);
        return max(ans1, ans2);
    }
};