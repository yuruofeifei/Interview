class Solution {
public:
    void sortColors(int A[], int n) {
        int i1 = 0, i2 = 0, i3 = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] == 2) {
                A[i3++] = 2;
            }
            else if (A[i] == 1) {
                A[i3++] = 2;
                A[i2++] = 1;
            }
            else {
                A[i3++] = 2;
                A[i2++] = 1;
                A[i1++] = 0;
            }
        }
    }
};