class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> ret;
        vector<int> v;
        ret.push_back(v);
        int size = 0, last = 0;
        for (int i = 0; i < S.size(); i++) {
            last = i >= 1 && S[i] == S[i - 1] ? size : 0;
            size = ret.size();
            for (int j = last; j < size; j++) {
                vector<int> temp = ret[j];
                temp.push_back(S[i]);
                ret.push_back(temp);
            }
        }
        return ret;
    }
};