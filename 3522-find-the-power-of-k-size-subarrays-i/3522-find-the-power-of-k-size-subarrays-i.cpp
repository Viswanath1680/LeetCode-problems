using vi = vector<int>;

class Solution {
public:
    vector<int> resultsArray(vector<int>& arr, int k) {
        if( k == 1 )    return arr;
        int n = arr.size();
        queue<int> q;
        vi ans;

        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1] + 1 )    q.push(i);
            if (i >= k - 1) {
                while (!q.empty() && q.front() <= (i - k + 1) )     q.pop();
                if (q.empty())    ans.emplace_back(arr[i]);
                else    ans.emplace_back(-1);
            }
        }
        return ans;
    }
};
