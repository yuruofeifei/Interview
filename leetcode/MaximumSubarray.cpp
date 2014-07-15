class Solution {
public:
    int maxSubArray(int A[], int n) {
        int m = numeric_limits<int>::min(), sum = 0;
        for (int i = 0; i < n; i++) {
            sum = A[i] + sum < 0 ? A[i] : sum + A[i];
            if (sum > m) m = sum;
            if (sum < 0) sum = 0;
        }
        return m;
    }
};