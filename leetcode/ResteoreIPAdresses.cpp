class Solution {
public:
    bool checkValid(string s) {
        if (s.empty()) return false;
        int base = 0;
        for (int i = 0; i < s.size(); i++) {
            base = 10 * base + (s[i] - '0');
        }
        if (s[0] == '0'  && s.size() > 1) return false;
        return base >= 0 && base <= 255;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        int size = s.size();
        for (int i = 0; i < min(3, size); i++) {
            for (int j = i + 1; j < min(i + 4, size); j++) {
                for (int k = j + 1; k < min(j + 4, size); k++) {
                    if (checkValid(s.substr(0, i + 1)) &&
                        checkValid(s.substr(i + 1, j - i)) &&
                        checkValid(s.substr(j + 1, k - j)) &&
                        checkValid(s.substr(k + 1, s.size() - k))) {
                            v.push_back(
                                s.substr(0, i + 1) + "." +
                                s.substr(i + 1, j - i) + "." +
                                s.substr(j + 1, k - j) + "." +
                                s.substr(k + 1, s.size() - k)
                            );
                    }
                }
            }
        }
        return v;
    }
};