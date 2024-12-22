class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0;
        for(int i = 0; i < k; i++) ans += arr[i];
        
        int curr = ans;
        for(int i = k-1; i >= 0; i--) {
            curr -= arr[i];
            curr += arr[n -k+i];			
			ans = max(ans, curr);
        }
        
        return ans;
    }
};