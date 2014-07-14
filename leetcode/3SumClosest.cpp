class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int dif = numeric_limits<int>::max();
        int ret = 0;
        sort(num.begin(), num.end());
        for (int i = 0; i < (int)num.size() - 2; i++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            int start = i + 1, end = num.size() - 1;
            while (start < end) {
                if (num[i] + num[start] + num[end] == target) {
                    return target;
                }
                else if (num[i] + num[start] + num[end] < target) {
                    if (abs(num[i] + num[start] + num[end] - target) < dif) {
                        dif = abs(num[i] + num[start] + num[end] - target);
                        ret = num[i] + num[start] + num[end];
                    }
                     start ++;
                }
                else {
                    if ((num[i] + num[start] + num[end] - target) < dif) {
                        dif = abs(num[i] + num[start] + num[end] - target);
                        ret = num[i] + num[start] + num[end];
                    }
                    end --;
                }
            }
        }
        return ret;
    }
};