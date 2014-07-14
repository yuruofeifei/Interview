class Solution {
public:
    static bool myfunction( const pair<int, int>& i, const pair<int, int>& j ) {
        if( i.first < j.first ) return true;
        return false;
    }
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int, int>> v;
        vector<int> r;
        for (int i = 0; i < numbers.size(); i++) {
            v.push_back(make_pair(numbers[i], i + 1));
        }
        sort(v.begin(), v.end(), myfunction);
        int start = 0, end = numbers.size() - 1;
        while (start < end) {
            if (v[start].first + v[end].first == target) {
                if (v[start].second < v[end].second) {
                    r.push_back(v[start].second); r.push_back(v[end].second);
                }
                else {
                    r.push_back(v[end].second); r.push_back(v[start].second); 
                }
                break;
            }
            else if (v[start].first + v[end].first < target) {
                start ++;
            }
            else end --;
        }
        return r;
    }
};