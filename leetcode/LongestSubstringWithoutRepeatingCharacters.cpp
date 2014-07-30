class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int table[256];
        for (int i = 0; i < 256; i++) {
            table[i] = -1;
        }
        int maxL = 0;
        int startIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (table[s[i]] >= 0) {
                if (i - startIndex > maxL) {
                    maxL = i - startIndex;
                }
                startIndex = table[s[i]] + 1;
                for (int j = 0; j < 256; j++) {
                    if (table[j] < startIndex) table[j] = -1;
                }
            }
            table[s[i]] = i;
        }
        return max(maxL, (int)s.size() - startIndex);
    }
};