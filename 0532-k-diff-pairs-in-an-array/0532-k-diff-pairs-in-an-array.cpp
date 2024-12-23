class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        if( k == 0 ){
            unordered_map<int, int> mp;
            for( auto it : arr )    mp[ it ]++;
            int answer = 0;
            for( auto it : mp )     if( it.second > 1 ) answer++;
            return answer;
        }

        set<int> s;
        for( auto it : arr )    s.insert( it );
        vector<int>temp;
        for( auto it : s )    temp.emplace_back( it );
        s.clear();
        unordered_map<int,int> ump;
        int answer = 0;
        for( int i = 0; i < temp.size(); i++ ){
            int target = temp[i] - k;
            if( ump.find( target ) != ump.end() )   answer++;
            ump[ temp[i] ]++;
        }
        return answer;

    }
};