using vvi = vector<vector<int>>;
using vi = vector<int>;
using vll = vector<long long>;
using pi = pair<int, int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;
using ll = long long;
using ull = unsigned long long;

// Use pq so that top element is always the max.
// But what if the top element is not in the window l - r?
// store every element in pq as {arr[i], i}
// So that if top element's ind i is < l, pop it. Do it until you find a valid max in the range of window
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        priority_queue<pi> pq;  // [arr[i], i]
        vi ans;
        int l = 0;
        for( int r = 0; r < arr.size(); r++ ){
            if( r-l+1 < k ){
                pq.push({arr[r], r});
            }
            else{
                pq.push( {arr[r], r} );
                while( pq.top().second < l  )    pq.pop();
                ans.emplace_back( pq.top().first );
                l++;
            }
        }
        return ans;
    }
};