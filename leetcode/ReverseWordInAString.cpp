class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int start = -1, end = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (start == -1) {
                    start = i;
                }
                end = i;
            }
            else {
                if (start != -1) {
                    for (int i = start; i <= (start + end) / 2; i++) {
                        char temp = s[i];
                        s[i] = s[end + start - i];
                        s[end + start - i] = temp;
                    }
                    start = -1;
                    end = -1;
                }
            }
        }
        for (int i = start; i <= (start + end) / 2; i++) {
            char temp = s[i];
            s[i] = s[end + start - i];
            s[end + start - i] = temp;
        }
        bool leading = true, continous = false;
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (leading) {
                    continue;
                }
                if (continous) {
                    continue;
                }
                continous = true;
            }
            else {
                leading = false;
                if (continous) s[index++] = ' ';
                continous = false;
                s[index++] = s[i];
            }
        }
        s.erase(s.begin() + index, s.end());
    }
};