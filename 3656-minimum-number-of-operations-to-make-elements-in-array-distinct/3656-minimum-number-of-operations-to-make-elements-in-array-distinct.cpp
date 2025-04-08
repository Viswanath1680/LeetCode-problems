class Solution {
public:
    int minimumOperations(vector<int>& arr) {
        vector<bool> check(101, false);
        int n = arr.size();
        int i = n;
        while( i-- ){
            if( check[arr[i]] )   break;
            else check[arr[i]] = true;
        }
        i++;
        int ans = i/3;
        if( i % 3 != 0 )    ans++;
        return ans;
    }
};