class Solution {
public:
    bool canJump(int A[], int n) {
        int maxRange = 0;
        for (int i = 0; i < n; i++) {
            if (maxRange < i) return false;
            if (A[i] + i > maxRange) maxRange = A[i] + i;
            if (maxRange >= n - 1) return true;
        }
        return false;
    }
};