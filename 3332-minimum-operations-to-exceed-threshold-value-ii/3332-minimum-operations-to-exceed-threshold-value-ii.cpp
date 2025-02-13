class Solution {
public:
    int minOperations(vector<int>& arr, int k) {
        // priority_queue <long, greater<long>> pq;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for( auto it : arr ) {
        if( it < k )    pq.push(it);
        }
        int ans = 0;
        while( pq.size() && pq.top() < k ){
            long long x, y;
            x = pq.top();
            pq.pop();
            if( pq.empty() ){
                ans++;
                break;
            }
            y = pq.top();
            pq.pop();
            pq.push( (long long)(2*min(x, y) + max(x, y)) );
            ans++;
        }
        return ans;
    }
};