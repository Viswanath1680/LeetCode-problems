class Solution {
public:
    int subarray_with_leq_k( vector<int>arr, int k ){
        int l = 0, r = 0, answer = 0;
        unordered_map<int,int> ump;
        while( r < arr.size() ){
            ump[ arr[r] ]++;
            while( ump.size() > k ){
                ump[ arr[l] ]--;
                if( ump[ arr[l] ] == 0 )    ump.erase( arr[l] );
                l++;
            }
            answer += ( r- l + 1);
            r++;
        }
        return answer;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarray_with_leq_k(nums, k) - subarray_with_leq_k(nums, k-1);
    }
};