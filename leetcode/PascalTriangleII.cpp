class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        v.push_back(1);
        for (int i = 1; i <= rowIndex; i++) {
            int last = v[0];
            for (int j = 1; j < v.size(); j++) {
                int temp = v[j];
                v[j] += last;
                last = temp;
            }
            v.push_back(1);
        }
        return v;
    }
};