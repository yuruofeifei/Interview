class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ret;
        sort(num.begin(), num.end());
        for (int i = 0; i < (int)num.size() - 2; i++) {//size_type unsigned int - 1 overflow
            if (i > 0 && num[i] == num[i - 1]) continue;
            int target = - num[i];
            int start = i + 1, end = num.size() - 1;
            while (start < end) {
                if (num[start] + num[end] == target) {
                    vector<int> v = {num[i], num[start], num[end]};
                    start ++; end --;
                    if (!ret.empty()) {
                        vector<int> &temp = ret.back();
                        if (temp[0] == v[0] && temp[1] == v[1] && temp[2] == v[2]) {
                            continue;
                        }
                    }
                    ret.push_back(v);
                }
                else if (num[start] + num[end] < target) {
                    start ++;
                }
                else {
                    end --;
                }
            }
        }
        return ret;
    }
};