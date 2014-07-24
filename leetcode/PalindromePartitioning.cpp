class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i < s.size() / 2; i++) {
			if(s[i] != s[s.size() - i - 1]) return false;
		}
		return true;
    }
    void generate(vector<int> *dp, string &s, int index, int n, vector<string> &v, vector<vector<string>> &ret) {
        if (index == n) {
            ret.push_back(v);
            return ;
        }
        for (int i : dp[index]) {
            v.push_back(s.substr(index, i - index));
            generate(dp, s, i, n, v, ret);
            v.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<int> dp[s.size() + 1];
        dp[s.size()].push_back(-1);
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j <= s.size(); j++) {
                if (isPalindrome(s.substr(i, j - i)) && !dp[j].empty()) {
                    dp[i].push_back(j);
                }
            }
        }
        vector<vector<string>> ret;
        vector<string> v;
        generate(dp, s, 0, s.size(), v, ret);
        return ret;
    }
};