class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> v1, v2;
        v1.push_back({});
        vector<vector<int>> &ret = v1, &v = v2;
        for (int i = 0; i < num.size(); i++) {
            for (int j = 0; j < ret.size(); j++) {
                for (int k = 0; k <= ret[j].size(); k++) {
                    vector<int> temp = ret[j];
                    temp.insert(temp.begin() + k, num[i]);
                    v.push_back(temp);
                }
            }
            vector<vector<int>> &mid = ret;
            ret = v;
            v = ret;
            v.clear();
        }
        return ret;
    }
};
