class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int numDigits = 0;
        int temp = x;
        while (temp > 0) {
            numDigits ++;
            temp /= 10;
        }
        for (int i = 0; i < numDigits / 2; i++) {
            int high = (x / (int)pow(10, numDigits - 1 - i)) % 10;
            int low = (x / (int)pow(10, i)) % 10;
            if (high != low)
                return false;
        }
        return true;
    }
};