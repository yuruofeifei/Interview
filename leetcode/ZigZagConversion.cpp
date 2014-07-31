class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) return s;
        int subL = (nRows - 1) * 2;
        string str[nRows];
        for (int i = 0; i < nRows; i++) str[i] = "";
        string ret;
        for (int i = 0; i <= s.size() / subL; i++) {
            for (int j = 0; j < nRows; j++) {
                if (i * subL + j >= s.size()) continue;
                str[j] += s[i * subL + j];
                if (i * subL + subL - j >= s.size() || j == 0 || j == nRows - 1) continue;
                str[j] += s[i * subL + subL - j];
            }
        }
        for (int i = 0; i < nRows; i++) ret += str[i];
        return ret;
    }
};