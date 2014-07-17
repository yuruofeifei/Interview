class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[mid][0] > target) {
                r = mid - 1;
            }
            else if (matrix[mid][0] < target) {
                l = mid + 1;
            }
            else {
                return true;
            }
        }
        if (r < 0) return false;
        int row = r;
        l = 0; r = matrix[row].size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[row][mid] > target) {
                r = mid - 1;
            }
            else if (matrix[row][mid] < target) {
                l = mid + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};