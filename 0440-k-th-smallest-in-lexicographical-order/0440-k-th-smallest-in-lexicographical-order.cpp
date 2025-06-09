class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            long long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }

    // calculates how many lexicographical numbers lie between curr and curr+1.
    long long countSteps(int n, long long n1, long long n2) {
        long long steps = 0;
        while (n1 <= n) {
            steps += min((long long)n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};
