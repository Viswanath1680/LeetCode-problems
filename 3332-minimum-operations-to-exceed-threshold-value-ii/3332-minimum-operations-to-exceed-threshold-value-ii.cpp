class Solution {
public:
    int minOperations(vector<int>& arr, int k) {
        // priority_queue <long, greater<long>> pq;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for( auto it : arr ) pq.push(it);
        int ans = 0;
        while( pq.size() >= 2 && pq.top() < k ){
            long long x, y;
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            pq.push( (long long)(2*min(x, y) + max(x, y)) );
            ans++;
        }
        return ans;
    }
};