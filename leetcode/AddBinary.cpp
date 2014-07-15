class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int ia = a.size() - 1, ib = b.size() - 1;
        int carry = 0;
        while (ia >= 0 && ib >= 0) {
            int sum = (a[ia] - '0') + (b[ib] - '0') + carry;
            if (sum >= 2) { sum -= 2; carry = 1; }
            else { carry = 0; }
            ret.push_back(sum + '0');
            ia --;
            ib --;
        }
        while (ia >= 0) {
            int sum = (a[ia] - '0') + carry;
            if (sum >= 2) { sum -= 2; carry = 1; }
            else { carry = 0; }
            ret.push_back(sum + '0');
            ia --;
        }
        while (ib >= 0) {
            int sum = (b[ib] - '0') + carry;
            if (sum >= 2) { sum -= 2; carry = 1; }
            else { carry = 0; }
            ret.push_back(sum + '0');
            ib--;
        }
        if (carry == 1)
            ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};