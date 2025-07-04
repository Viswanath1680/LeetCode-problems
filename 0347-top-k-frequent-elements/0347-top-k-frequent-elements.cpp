using pi = pair<int, int>;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for( auto it : nums )   ump[it]++;
        priority_queue<pi, vector<pi>, greater<pi>> minHeap;
        for( auto p : ump ){
            minHeap.push({p.second, p.first});
            if( minHeap.size() > k )    minHeap.pop();
        }
        vector<int> ans;
        while( !minHeap.empty() ){
            ans.emplace_back( minHeap.top().second );
            minHeap.pop();
        }
        return ans;
    }
};