class Solution {
public:
    int reverse(int x) {
        int negtive = 1;
        if (x == 0) return 0;
        if (x < 0) { x = -x; negtive = -1;}
        int numDigits = 0;
        int temp = x;
        while (temp != 0) {
            temp /= 10;
            numDigits ++;
        }
        for (int i = 0; i <= (numDigits - 1) / 2; i++) {
            int high = x / (int)pow(10, numDigits - i - 1) % 10;
            int low = x / (int)(pow(10, i)) % 10;
            x += (low - high) * (int)pow(10, numDigits - i - 1);
            x += (high - low) * (int)pow(10, i);
        }
        return x * negtive;
    }
};