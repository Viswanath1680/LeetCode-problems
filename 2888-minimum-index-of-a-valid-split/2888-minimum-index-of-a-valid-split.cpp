class Solution {
public:
    pair<int, int> dominantelement(vector<int>& arr){
        int n = arr.size();
        int ans = arr[0], count = 1;
        for( int i = 1; i < n; i++ ){
            if( arr[i] == ans ) count++;
            else{
                count--;
                if( count == 0 )    {
                    ans = arr[i];
                    count = 1;
                }
            }
        }
        count = 0;
        for( auto it : arr )    if( ans == it ) count++;
        return {ans, count};
    }

    int minimumIndex(vector<int>& arr) {
        int n = arr.size();
        auto pair = dominantelement(arr);
        int dom = pair.first, dom_count = pair.second;
        // cout << dom;
        int count = 0;
        for( int i = 0; i < n; i++ ){
            if( arr[i] == dom ) count++;
            if( count > (i+1)/2 )  {
                int other_size = (n-1-i);
                int diff = dom_count - count;
                if( diff > other_size/2 )   return i;
                return -1;
            }
        }
        return -1;
    }
};