class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        string s = "1";
        for (int j = 1; j < n; j++) {
            int i = 0;
            string temp;
            while (i < s.size()) {
                char c = s[i];
                int repeat = 0;
                while (c == s[i]) {
                    i ++;
                    repeat ++;
                    if (i == s.size()) break;
                }
                temp += ('0' + repeat);
                temp +=  c;
            }
            s = temp;
        }
        return s;
    }
};