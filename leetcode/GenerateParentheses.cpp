class Solution {
public:
    void generate(int left, int n, string s, vector<string> &ret) {
        if (n == 0) {
            ret.push_back(s);
            return ;
        }
        if (left < n) generate(left + 1, n, s + "(", ret);
        if (left > 0) generate(left - 1, n - 1, s + ")", ret);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generate(0, n, "", ret);
        return ret;
    }
};
