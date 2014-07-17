class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int start = -1;
        int length = 0;
        for (int i = 0; *s != '\0'; i++, s++) {
            if (*s != ' ') {
                if (start == -1) {
                    start = i;
                    length = 1;
                }
                else {
                    length = i - start + 1;
                }
            }
            else {
                start = -1;
            }
        }
        return length;
    }
};