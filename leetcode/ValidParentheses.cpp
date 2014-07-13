class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') 
                stack.push_back(c);
            else {
                if (stack.empty()) {
                    return false;
                }
                if (c == ')' && stack.back() == '(') {
                    stack.pop_back();
                }
                else if (c == ']' && stack.back() == '[') {
                    stack.pop_back();
                }
                else if (c == '}' && stack.back() == '{') {
                    stack.pop_back();
                }
                else {
                    return false;
                }
            }
        }
        if (stack.empty()) 
            return true;
        else 
            return false;
    }
};