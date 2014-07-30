class Solution {
public:
    void generate(int n, int index, int k, vector<int> &v, vector<vector<int>> &ret) {
        if (v.size() == k) {
            ret.push_back(v);
            return ;
        }
        for (int i = index; i <= n; i++) {
            v.push_back(i);
            generate(n, i + 1, k, v, ret);
            v.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> v;
        generate(n, 1, k, v, ret);
        return ret;
    }
};