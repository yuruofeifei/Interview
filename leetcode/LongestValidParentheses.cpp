class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;
        stack.push_back(-1);
        int maxL = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && stack.size() > 1 && s[stack.back()] == '(') {
                stack.pop_back();
                if (maxL < i - stack.back()) maxL = i - stack.back();
            }
            else {
                stack.push_back(i);
            }
        }
        return maxL;
    }
};