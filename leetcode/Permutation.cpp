class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> *ret = new vector<vector<int>>();
        if (num.empty()) return *ret;
        vector<int> v = {num[0]};
        ret->push_back(v);
        vector<vector<int>> *p = new vector<vector<int>>();
        for(int i = 1; i < num.size(); i++) {
            for (int j = 0; j < ret->size(); j++) {
                for (int k = 0; k <= i; k++) {
                    vector<int> temp = ret->at(j);
                    temp.insert(temp.begin() + k, num[i]);
                    p->push_back(temp);
                }
            }
            vector<vector<int>> *mid = ret;
            ret = p;
            p = mid;
            p->clear();
        }
        return *ret;
    }
};