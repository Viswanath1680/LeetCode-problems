class Solution {
public:
    int nC2(int n){
        return ( n*(n-1)/2 );
    }

    int tupleSameProduct(vector<int>& arr) {
        set <int> s;
        for(auto it : arr)  s.insert(it);

        arr.clear();
        for(auto it : s)    arr.emplace_back(it);

        int n = arr.size();
        unordered_map<int, int> ump;
        for( int i = 0; i < n-1; i++ ){
            for( int j = i+1; j < n; j++ ){
                int product = arr[i]*arr[j];
                ump[ product ]++;
            }
        }

        int ans = 0;
        for( auto it : ump ){
            if( it.second < 2 ) continue;
            int combos = nC2(it.second);
            ans += 8*combos;
        }
        return ans;
    }
};