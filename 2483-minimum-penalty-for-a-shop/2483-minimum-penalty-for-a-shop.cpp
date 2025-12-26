class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        vector<int> prefixN(n + 1, 0), suffixY(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefixN[i + 1] = prefixN[i] + (customers[i] == 'N');

        for (int i = n - 1; i >= 0; i--)
            suffixY[i] = suffixY[i + 1] + (customers[i] == 'Y');

        int minPenalty = INT_MAX;
        int bestHour = 0;

        for (int j = 0; j <= n; j++) {
            int penalty = prefixN[j] + suffixY[j];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j;
            }
        }

        return bestHour;
    }
};
