class Solution {
public:
    double recursive_pow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double p = recursive_pow(x, n / 2);
        if (n % 2 == 0) return p * p;
        else return p * p * x;
    }
    double pow(double x, int n) {
        if (n > 0) return recursive_pow(x, n);
        else return 1.0 / recursive_pow(x, n);
    }
};