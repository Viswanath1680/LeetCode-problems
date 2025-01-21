class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), l = 0, r = 0, ans = 0;
        map<int,int> mp;
        int sum = 0;
        while( r < n ){
            mp[ fruits[r] ]++;
            sum++;
            if( mp.size() <= 2 ){
                ans = max( sum, ans );
            }
            r++;
            if( mp.size() > 2 ){
                while( mp.size() > 2 ){
                    mp[ fruits[l] ]--;
                    if( mp[ fruits[l] ] == 0 )  mp.erase( fruits[l] );
                    sum --;
                    l++;
                }
            }
        }
        return ans;
    }
};