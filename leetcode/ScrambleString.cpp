class Solution {
public:
    bool isScramble(string s1, string s2) {
        int size = s1.size();
        if (size == 0) return true;
        if (s1 == s2) return true;
        char c1[256], c2[256];
        for (int i = 0; i < 256; i++) { c1[i] = 0; c2[i] = 0; }
        for (int i = 0; i < size; i++) { c1[s1[i]]++; c2[s2[i]]++;}
        for (int i = 0; i < 256; i++) if (c1[i] != c2[i]) return false;
        for (int i = 0; i < size - 1; i++) {
            if ((isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) &&
                isScramble(s1.substr(i + 1), s2.substr(i + 1))) ||
                (isScramble(s1.substr(0, i + 1), s2.substr(size - i - 1)) &&
                isScramble(s1.substr(i + 1), s2.substr(0, size - i - 1)))
            ) return true;
        }
        return false;
    }
};