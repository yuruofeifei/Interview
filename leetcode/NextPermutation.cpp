class Solution {
public:
    void nextPermutation(vector<int> &num) {
        bool exist = false;
        for (int i = num.size() - 2; i >= 0; i--) {
            if (num[i] < num[i + 1]) {
                int j = i + 1;
                for (; j <= num.size(); j++) {
                    if (j == num.size() || num[i] >= num[j]) {
                        int temp = num[i];
                        num[i] = num[j - 1];
                        num[j - 1] = temp;
                        break;
                    }
                }
                reverse(num.begin() + i + 1, num.end());
                exist = true;
                break;
            }
        }
        if (!exist) reverse(num.begin(), num.end());
    }
};