class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int l = 0; l <= min(i, (int)s.size() - i - 1); l++) {
                if (s[i - l] != s[i + l]) 
                    break;
                else if (2 * l + 1 >= end - start + 1) {
                    start = i - l; end = i + l;
                }
            }
            if (i < s.size() - 1) {
                for (int l = 0; l <= min(i, (int)s.size() - i - 2); l++) {
                    if (s[i - l] != s[i + 1 + l]) 
                        break;
                    else if (2 * l + 2 >= end - start + 1) {
                        start = i - l; end = i + 1 + l;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};