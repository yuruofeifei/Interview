class Solution {
public:
    vector<int> search(int A[], int start, int end, int target) {
        if (start > end) return {-1, -1};
        int mid = (start + end) / 2;
        if (A[mid] > target) {
            return search(A, start, mid - 1, target);
        }
        else if (A[mid] < target) {
            return search(A, mid + 1, end, target);
            
        }
        vector<int> l = search(A, start, mid - 1, target);
        vector<int> r = search(A, mid + 1, end, target);
        vector<int> ret = {mid, mid};
        if (l[0] >= 0) { ret[0] = l[0]; }
        if (r[1] >= 0) { ret[1] = r[1]; }
        return ret;
    }
    vector<int> searchRange(int A[], int n, int target) {
        return search(A, 0, n - 1, target);
    }
};