
class Solution {
public:
    int findPivot(int A[], int start, int end) {
        if (end - start <= 1) {
            if (A[start] < A[end]) return start;
            else return end;
        }
        int mid = (start + end) / 2;
        if (A[end] <  A[mid]) {
            return findPivot(A, mid, end);
        }
        else {
            return findPivot(A, start, mid);
        }
    }
    int bsearch(int A[], int start, int end, int pivot, int target, int n) {
        if (start > end) {
            return -1;
        }
        int mid = ((start + end) / 2 + pivot) % n;
        if (A[mid] == target) {
            return mid;
        }
        else if (A[mid] > target) {
            return bsearch(A, start, (start + end) / 2 - 1, pivot, target, n);
        }
        else {
            return bsearch(A, (start + end) / 2 + 1, end, pivot, target, n);
        }
    }
    int search(int A[], int n, int target) {
        int pivot = findPivot(A, 0, n - 1);
        return bsearch(A, 0, n - 1, pivot, target, n);
    }
};