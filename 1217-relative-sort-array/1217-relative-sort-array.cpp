class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        unordered_map<int, int> mp;
        for( int i = 0; i < n; i++ )    mp[ arr2[i] ] = i;
        vector<int> count(n, 0), temp;
        for( int i = 0; i < arr1.size(); i++){
            if( mp.find( arr1[i] ) == mp.end() ) temp.emplace_back( arr1[i] );
            else{
                int ind = mp[ arr1[i] ];
                count[ind]++;
            }
        }
        vector<int> answer;
        for( int i = 0; i < n; i++ ){
            while( count[i]-- )     answer.emplace_back( arr2[i] );
        }
        sort(temp.begin(),temp.end());
        answer.insert(answer.end(), temp.begin(), temp.end());
        return answer;
    }
};