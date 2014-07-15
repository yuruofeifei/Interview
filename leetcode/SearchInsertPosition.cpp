class Solution {
public:
    int search(int A[], int start, int end, int target) {
        if (start > end) {
            return start;
        }
        int mid = (start + end) / 2;
        if (A[mid] == target) {
            return mid;
        }
        else if (A[mid] > target) {
            return search(A, start, mid - 1, target);
        }
        else {
            return search(A, mid + 1, end, target);
        }
    }
    int searchInsert(int A[], int n, int target) {
        return search(A, 0, n - 1, target);
    }
};