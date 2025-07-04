class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int> maxHeap;    // for numbers in arr less than x
        priority_queue<int, vector<int>, greater<int>> minHeap; // greater than x
        for( auto num : arr ){
            if( num <= x )  maxHeap.push(num);
            else    minHeap.push(num);
        }
        vector<int> ans;
        while (k--) {
            if (maxHeap.empty()) {
                ans.emplace_back(minHeap.top());
                minHeap.pop();
            } 
            else if (minHeap.empty()) {
                ans.emplace_back(maxHeap.top());
                maxHeap.pop();
            } 
            else {
                int diff1 = x - maxHeap.top();
                int diff2 = minHeap.top() - x;
                if (diff1 <= diff2) {
                    ans.emplace_back(maxHeap.top());
                    maxHeap.pop();
                } 
                else {
                    ans.emplace_back(minHeap.top());
                    minHeap.pop();
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};