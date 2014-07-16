class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        int repeat = 0;
        int index = 0;
        int cur = A[0];
        for (int i = 0; i < n; i++) {
            if (A[i] == cur) { 
                if (repeat < 2) A[index++] = A[i]; 
                repeat++;
            } 
            else {
                cur = A[i];
                A[index++] = cur;
                repeat = 1;
            }
        }
        return index;
    }
};