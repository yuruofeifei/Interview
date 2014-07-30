class Solution {
public:
    void generate(string& digits, int index, string s, string map[], vector<string> &ret) {
        if (index == digits.size()) {
            ret.push_back(s);
            return ; 
        }
        for (char c : map[(digits[index] - '0') - 2]) {
            generate(digits, index + 1, s + c, map, ret);
        }
    }
    vector<string> letterCombinations(string digits) {
        string map[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        generate(digits, 0, "", map, ret);
        return ret;
    }
};