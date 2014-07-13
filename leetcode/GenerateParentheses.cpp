class Solution {
public:
    void generate(vector<string> &v, string s, int left, int right, int n) {
        if (right == n) v.push_back(s);
        if (left < n) generate(v, s + "(", left + 1, right, n);
        if (left > right) generate(v, s + ")", left, right + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        generate(v, "(", 1, 0, n);
        return v;
    }
};