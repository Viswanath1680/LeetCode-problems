class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;

        vector<int> seatPos;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                seatPos.push_back(i);
            }
        }

        if (seatPos.size() == 0 || seatPos.size() % 2 != 0) {
            return 0;
        }

        long long result = 1;

        for (int i = 2; i < seatPos.size(); i += 2) {
            int prevSecondSeat = seatPos[i - 1];
            int nextFirstSeat = seatPos[i];
            int plantsBetween = nextFirstSeat - prevSecondSeat - 1;
            result = (result * (plantsBetween + 1)) % MOD;
        }

        return result;
    }
};
