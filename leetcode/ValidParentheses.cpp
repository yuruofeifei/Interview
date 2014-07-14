bool isValid(string s) {
        vector<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if (stack.size() == 0) stack.push_back(s[i]);
            else {
                char c = stack.back();
                if ((s[i] == ')' && c == '(') 
                || (s[i] == ']' && c == '[') 
                || (s[i] == '}' && c == '{')) 
                    stack.pop_back();
                else stack.push_back(s[i]);
            }
        }
        if (stack.size() == 0) return 1;
        return 0;
    }