class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> ret;
        vector<vector<int>> &cur = ret;
        
        vector<vector<int>> vec;
        vector<vector<int>> &next = vec;
        
        if (num.empty()) return cur;
        sort(num.begin(), num.end());
        vector<int> v = {num[0]};
        cur.push_back(v);
        for (int i = 1; i < num.size(); i++) {
            bool repeat = num[i] == num[i - 1];
            for (int j = 0; j < cur.size(); j++) {
                for (int k = i; k >= 0; k--) {
                    vector<int> temp = cur[j];
                    temp.insert(temp.begin() + k, num[i]);
                    next.push_back(temp);
                    if (repeat && temp[k - 1] == num[i]) break;
                }
            }
            vector<vector<int>> &mid = cur;
            cur = next;
            next = mid;
            next.clear();
        }
        return cur;
    }
};