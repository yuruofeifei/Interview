class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x < 0) {x = -x; sign = -1;}
        int ret = 0;
        while (x) {
            ret = 10 * ret + (x % 10);
            x /= 10;
        }
        return ret * sign;
    }
};
