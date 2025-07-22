// Typical sliding window problem
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& arr) {
        vector<bool> seen(10001, false);
        int ans = 0, sum = 0;
        int i = 0, j = 0;
        while( j < arr.size() ){
            if( seen[arr[j]] == false ){
                seen[ arr[j] ] = true;
                sum += arr[j];
                ans = max(ans, sum);
                j++;
            }
            else{
                while( i < j && seen[ arr[j] ] == true ){
                    // s.erase( arr[i] );
                    seen[ arr[i] ] = false;
                    sum -= arr[i];
                    i++;
                }
            }
        }
        return ans;
    }
};