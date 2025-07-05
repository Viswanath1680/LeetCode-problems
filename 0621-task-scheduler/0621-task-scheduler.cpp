// Neetcode Solution
// https://www.youtube.com/watch?v=s8p8ukTyA2I

using pi = pair<int, int>;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for( auto c : tasks )   freq[ c-'A' ]++;
        priority_queue<int> maxHeap;
        for( auto f : freq )    if( f ) maxHeap.push(f);
        queue<pi> q;
        int time = 0;
        while( maxHeap.size() || q.size() ){
            time++;
            if( maxHeap.size() ){
                auto f = maxHeap.top();
                maxHeap.pop();
                f--;
                if( f ) q.push( {f, time+n} );
            }
            if( q.size() && (q.front().second == time) ){
                auto f = q.front().first;
                maxHeap.push(f);
                q.pop();
            }
        }
        return time;
    }
};