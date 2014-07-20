class Solution {
public:
    int maxArea(vector<int> &height) {
        int low = 0, high = height.size() - 1, area = 0;
        while (low < high) {
            area = max(area, (high - low) * min(height[low], height[high]));
            if (height[low] > height[high]) {
                high --;
            }
            else {
                low ++;
            }
        }
        return area;
    }
};