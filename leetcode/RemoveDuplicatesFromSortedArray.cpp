class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        int index = 0;
        int cur = A[index++];
        for (int i = 1; i < n; i++) {
            if (cur != A[i]) { cur = A[i]; A[index++] = A[i]; }
        }
        return index;
    }
};