class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, int> hash;
        for (string &s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            if (hash.find(temp) == hash.end()) {
                hash[temp] = 1;
            }
            else {
                hash[temp] += 1;
            }
        }
        int index = 0;;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (hash[temp] > 1) {
                strs[index++] = strs[i];
            }
        }
        strs.erase(strs.begin() + index, strs.end());
        return strs;
    }
};