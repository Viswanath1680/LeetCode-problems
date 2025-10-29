// prefix sum and suffix sum of a zero element should be same inorder to be valid. So that we can bounce on both sides and make them 0. -> ans += 2
// This implies if left dir == right dir (when prefix sum == suffix sum)
// else ans += 1

using vi = vector<int>;
class Solution {
public:
    int countValidSelections(vector<int>& arr) {
        int n = arr.size();
        vi prefix(n, 0), suffix(n, 0);
        prefix[0] = arr[0];
        for( int i = 1; i < n; i++ )    prefix[i] = prefix[i-1] + arr[i];

        suffix[n-1] = arr[n-1];
        for( int i = n-2; i >= 0; i-- ) suffix[i] = suffix[i+1] + arr[i];

        int ans = 0;
        for( int i = 0; i < n; i++ ){
            if( arr[i] != 0 )   continue;
            if( prefix[i] == suffix[i] )    ans += 2;
            else if( abs( prefix[i] - suffix[i] ) == 1  )  ans++;
        }
        return ans;
    }
};