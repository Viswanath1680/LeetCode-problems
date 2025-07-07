// Initial thought:
// Multiple events can overlap, but picking the earliest end day always leaves room for future events.
// Short-duration events aren't always best unless they also end soon.


class Solution {
public:
    // Choose the event that ends the earliest  
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int day = 0, ans = 0, i = 0, n = events.size();

        while (i < n || !minHeap.empty()) {
            if (minHeap.empty())    day = events[i][0];

            // Adding events that start today
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                i++;
            }

            // Removing events that are already expired
            while (!minHeap.empty() && minHeap.top() < day)    minHeap.pop();

            if (!minHeap.empty()) {
                minHeap.pop(); // Attend event with earliest end
                ans++;
            }
            day++;
        }

        return ans;
    }
};