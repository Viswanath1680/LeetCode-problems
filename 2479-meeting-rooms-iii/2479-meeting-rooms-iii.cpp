using pli = pair<long long, int>;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int> countOfEachRoom(n, 0);
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; ++i) freeRooms.push(i);
        // {end time, room number}
        priority_queue<pli, vector<pli>, greater<>> busyRooms;

        for (auto& meet : meetings) {
            int start = meet[0], end = meet[1];
            // Free up rooms that have completed meetings by current start
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }
            if (!freeRooms.empty()) {
                // Assign to the lowest-numbered available room
                int room = freeRooms.top();
                freeRooms.pop();
                busyRooms.push({end, room});
                countOfEachRoom[room]++;
            } 
            else {
                // No room free → delay to the earliest available room
                auto [endTime, room] = busyRooms.top();
                busyRooms.pop();

                long long duration = end - start;
                long long newEnd = endTime + duration;
                busyRooms.push({newEnd, room});
                countOfEachRoom[room]++;
            }
        }

        // Find room with max meetings (smallest index on tie)
        int maxRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (countOfEachRoom[i] > countOfEachRoom[maxRoom]) maxRoom = i;
        }
        return maxRoom;
    }
};