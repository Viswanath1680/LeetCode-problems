class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        int n = arr.size();
        int answer = 0;
        // for( auto & it : arr )    it = abs(it);
        arr[0] = ((arr[0] % k) + k) % k;
        for( int i = 1; i < n; i++) arr[i] = (( arr[i] + arr[i-1] )% k + k ) % k;
        unordered_map<int,int> ump;
        for( int i = 0; i < n; i++ ){
            answer += ump[ arr[i] ];
            if( arr[i] == 0 )   answer++;
            ump[ arr[i] ]++;
        }
        return answer;
    }
};