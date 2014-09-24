class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return {0};
        vector<int> v = {0, 1};
        int base = 2;
        for (int i = 1; i < n; i++) {
            for (int j = base - 1; j >= 0; j--) {
                v.push_back(v[j] + base);
            }
            base *= 2;
        }
        return v;
    }
};
