class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int goal) {
        for( int i = 1; i < arr.size(); i++ )   arr[i] += arr[i-1];
        unordered_map<int,int> ump;
        int answer = 0;
        for( int i = 0; i < arr.size(); i++ ){
            int target = arr[i] - goal;
            if( ump[ target ] ) answer += ump[ target ];
            if( arr[i] == goal )    answer++;
            ump[ arr[i] ]++;
        }
        return answer;
    }
};