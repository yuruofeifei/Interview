class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            char left, right;
            if (s[start] >= 97 && s[start] <= 122) {
                left = s[start] - 32;
            }
            else if ((s[start] >= 65 && s[start] <= 90) || (s[start] >= 48 && s[start] <= 57)) {
                left = s[start];
            }
            else {
                start ++;
                continue;
            }
            
            if (s[end] >= 97 && s[end] <= 122) {
                right = s[end] - 32;
            }
            else if ((s[end] >= 65 && s[end] <= 90) || (s[end] >= 48 && s[end] <= 57)) {
                right = s[end];
            }
            else {
                end --;
                continue;
            }
            
            if (left == right) {
                start ++;
                end --;
            }
            else {
                return false;
            }
        }
        return true;
    }
};