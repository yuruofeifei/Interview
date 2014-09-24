class Solution {
public:
    int singleNumber(int A[], int n) {
        int count[32];
        for (int i = 0; i < 32; i++) count[i] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if (A[i] & (1 << j)) count[j] = (count[j] + 1) % 3;
            }
        }
        int ret = 0;
        for (int i = 0; i < 32; i++) if (count[i] == 1) ret |= (1 << i);
        return ret;
    }
};
