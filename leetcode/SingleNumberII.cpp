class Solution {
public:
    int singleNumber(int A[], int n) {
        int single = 0;
        int count[32] = {0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if ((A[i] >> j) & 1) {
                    count[j] ++;
                    if (count[j] == 3) {
                        single &= ~(1 << j);
                        count[j] = 0;
                    }
                    if (count[j] == 1) {
                        single |= (1 << j);
                    }
                }
            }
        }
        return single;
    }
};