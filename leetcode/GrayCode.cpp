class Solution {
public:
    void gray(int digit, int n, vector<int> &v) {
        if (digit == n) {
            return;
        }
        int add = 1 << digit;
        int size = v.size();
        for (int i = size - 1; i >= 0; i--) {
            v.push_back(v[i] + add);
        }
        gray(digit + 1, n, v);
    }
    vector<int> grayCode(int n) {
        vector<int> v; v.push_back(0); 
        gray(0, n, v);
        return v;
    }
};
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        v.push_back(0);
        if (n == 0) return v;
        v.push_back(1);
        for (int i = 1; i < n; i++) {
            int nn = v.size();
            int mm = 1 << i;
            for (int j = 0; j < mm; j++) {
                v.push_back(nn + v[mm - j - 1]);
            }
        }
        return v;
    }
};