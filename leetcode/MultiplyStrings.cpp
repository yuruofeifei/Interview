class Solution {
public:
    string multiply(string num1, string num2) {
        string ret(num1.size() + num2.size(), '0');
        int carry = 0;
        for (int i = num2.size() - 1; i >= 0; i--) {
            carry = 0;
            int m1 = (num2[i] - '0');
            for (int j = num1.size() - 1; j >= 0; j--) {
                int m2 = (num1[j] - '0');
                int m = m1 * m2 + carry + (ret[i + j + 1] - '0');
                carry = m / 10;
                ret[i + j + 1] = (m % 10 + '0');
            }
            ret[i] = (carry + '0');
        }
        int count = 0;
        while (count < ret.size() && ret[count] == '0') count++;
        if (count == ret.size()) return "0";
        return ret.substr(count);
    }
};