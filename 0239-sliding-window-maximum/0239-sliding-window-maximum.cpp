class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        list<int> l;
        l.push_back(arr[0]);
        for( int i = 1; i < k; i++){
            while( !l.empty() && arr[i] > l.back() ) l.pop_back();
            l.push_back(arr[i]);
        }
        vector<int> ans;
        ans.push_back(l.front());
        for( int i = k; i < n ; i++){
            if( arr[i-k] == l.front() )     l.pop_front();
            while( !l.empty() && arr[i] > l.back() ) l.pop_back();
            l.push_back(arr[i]);
            ans.push_back(l.front());
        }
        return ans;
    }
};