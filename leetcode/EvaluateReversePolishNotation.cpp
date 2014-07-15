class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> stack;
        for (string &s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int l, r;
                if (stack.size() == 1) {
                    l = 0; r = stack.back(); stack.pop_back();
                }
                else {
                    r = stack.back(); stack.pop_back();
                    l = stack.back(); stack.pop_back();
                }
                if (s == "+") stack.push_back(l + r);
                if (s == "-") stack.push_back(l - r);
                if (s == "*") stack.push_back(l * r);
                if (s == "/") stack.push_back(l / r);
            }
            else {
                stack.push_back(stoi(s));
            }
        }
        return stack.back();
    }
};