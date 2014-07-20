class Solution {
public:
    void combine(int target, vector<int> &candidates, vector<int> &sum, vector<vector<int>> &ret, int start) {
        if (target < 0) return;
        if (target == 0) { ret.push_back(sum); return ;}
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            sum.push_back(candidates[i]);
            combine(target - candidates[i], candidates, sum, ret, i + 1);
            sum.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int>> ret;
        vector<int> sum;
        combine(target, num, sum, ret, 0);
        return ret;
    }
};