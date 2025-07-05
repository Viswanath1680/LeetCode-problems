using pi = pair<int, int>;
class Solution {
public:
    // comparator should return b
    struct Compare{
        bool operator()(const pi& a, const pi& b){
            if( a.first == b.first )    return a.second < b.second;
            return a.first > b.first;
        }
    };

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> ump;
        for( auto it : nums )   ump[it]++;
        priority_queue<pi, vector<pi>, Compare> minHeap;
        for( auto [key, freq] : ump )   minHeap.push( {freq, key} );
        vector<int> ans;
        while( !minHeap.empty() ){
            auto [freq, key] = minHeap.top();
            minHeap.pop();
            while( freq-- ) ans.emplace_back(key);
        }
        return ans;
    }
};