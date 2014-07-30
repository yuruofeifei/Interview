class Solution {
public:
    int jump(int A[], int n) {
        int step = 0;
        int maxRange = 0;
        int lastMaxRange = 0;
        for (int i = 0; i < n; i++) {
            if (i > lastMaxRange) {
                lastMaxRange = maxRange;
                step++;
            }
            maxRange = max(A[i] + i, maxRange);
        }
        return step;
    }
};