class Solution {
public:
    bool process(vector<int>arr, vector<vector<int>>& queries, int k){
        int n = arr.size();
        vector<int> temp(n + 1, 0);
        for(int i = 0; i < k; i++){
            int left = queries[i][0], right = queries[i][1], val = queries[i][2];
            temp[left] += val;
            temp[right + 1] -= val;
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += temp[i];
            if(sum < arr[i])    return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& arr, vector<vector<int>>& queries) {
        bool all_zeroes = true;
        for( auto it : arr )    if( it != 0 )   all_zeroes = false;
        if( all_zeroes )    return 0;

        int m = arr.size(), n = queries.size();
        int ans = -1, l = 1, r = n;
        while( l <= r ){
            int mid = l + (r-l)/2;
            bool val = process(arr, queries, mid);
            if( val )   r = mid-1, ans = mid;
            else    l = mid+1;
        }
        return ans;
    }   
};