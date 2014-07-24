class Solution {
public:
    int divide(int dividend, int divisor) {
        long long dividend_ = dividend, divisor_ = divisor;
        int isPos = 1;
        if (dividend_ < 0) {
            isPos =  -isPos;
            dividend_ = - dividend_;
        }
        if (divisor_ < 0) {
            isPos = - isPos;
            divisor_ = - divisor_;
        }
        int sum = 0;
        while (dividend_ != 0) {
            long long base = divisor_;
            long long count = 1;
            if (dividend_ < base) break;
            while (dividend_ >= base) {
                dividend_ -= base;
                sum += count;
                count += count;
                base <<= 1;
            }
        }
        return sum * isPos;
    }
};