class Solution {
public:
    
    bool bsearch(int A[], int start, int end, int target) {
        if (start > end) {
            return false;
        }
        int mid = (start + end) / 2;
        if (A[mid] == target) {
            return true;
        }
        bool l = false, r = false;
        if (A[mid] > target) {
            l = bsearch(A, start, mid - 1, target);
            if (A[mid] >= A[end]) {
                r = bsearch(A, mid + 1, end, target);
            }
        }
        else {
            r = bsearch(A, mid + 1, end, target);
            if (A[start] >= A[mid]) {
                l = bsearch(A, start, mid - 1, target);
            }
        }
        return l || r;
    }
    bool search(int A[], int n, int target) {
        return bsearch(A, 0, n - 1, target);
    }
};