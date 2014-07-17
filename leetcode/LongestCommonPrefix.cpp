class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        string s = "";
        int index = 0;
        bool go = true;
        while (go) {
            if (index >= strs[0].size()) break;
            char c = strs[0][index];
            int i;
            for (i = 0; i < strs.size(); i++) {
                if (index >= strs[i].size() || strs[i][index] != c) {go = false; break;}
            }
            if (i == strs.size()) s += c;
            index ++;
        }
        return s;
    }
};