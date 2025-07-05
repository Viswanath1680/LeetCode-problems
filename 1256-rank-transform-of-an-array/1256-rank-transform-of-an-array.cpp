class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> ump;
        priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
        int rank = 1;
        while( !minHeap.empty() ){
            auto num = minHeap.top();
            minHeap.pop();
            if( ump.find( num ) == ump.end() ){
                ump[num] = rank;
                rank++;
            }
        }
        vector<int> ans;
        for( auto num : arr )   ans.emplace_back( ump[num] );
        return ans;
    }
};