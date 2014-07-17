class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> ret;
        vector<int> v;
        ret.push_back(v);
        for (int i = 0; i < S.size(); i++) {
            int size = ret.size();
            for (int j = 0; j < size; j++) {
                vector<int> temp = ret[j];
                temp.push_back(S[i]);
                ret.push_back(temp);
            }
        }
        return ret;
    }
};