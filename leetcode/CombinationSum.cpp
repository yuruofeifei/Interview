class Solution {
public:
    void combine(int target, vector<int> &candidates, vector<int> &sum, vector<vector<int>> &ret, int start) {
        if (target < 0) return;
        if (target == 0) { ret.push_back(sum); return ;}
        for (int i = start; i < candidates.size(); i++) {
            sum.push_back(candidates[i]);
            combine(target - candidates[i], candidates, sum, ret, i);
            sum.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        vector<vector<int>> ret;
        vector<int> sum;
        combine(target, candidates, sum, ret, 0);
        return ret;
    }
};