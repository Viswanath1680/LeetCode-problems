class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        for( int i = 0; i < n; ){
            vector<int> temp;
            if( arr[i] + k < arr[i+2] ){
                ans.clear();
                return ans;
            }
            temp.emplace_back(arr[i]);
            temp.emplace_back(arr[i+1]);
            temp.emplace_back(arr[i+2]);
            ans.emplace_back(temp);
            i += 3;
        }
        return ans;
    }
};