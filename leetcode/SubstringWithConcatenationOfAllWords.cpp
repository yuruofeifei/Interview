class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> v;
        if (L.empty()) return v;
        unordered_map<string, int> hash(L.size());
        int used[L.size()];
        for (int i = 0; i < L.size(); i++) {
            used[i] = 0;
        }
        for (int i = 0; i < L.size(); i++) {
            if (hash.count(L[i]) == 0) {
                hash[L[i]] = i;
            }
            used[hash[L[i]]] ++;
        }
        int temp[L.size()];
        int size = L[0].size();
        for (int i = 0; i <= int(S.size() - size * L.size()); i++) {
            int count = 0;
            
            for (int j = 0; j < L.size(); j++) {
                temp[j] = used[j];
            }
            for (int j = 0; j < L.size(); j++) {
                string sub = S.substr(i + size * j, size);
                if (hash.count(sub) > 0 && temp[hash[sub]] > 0) {
                    temp[hash[S.substr(i + size * j, size)]] --;
                    count++;
                }
                else {
                    break;
                }
            }
            if (count == L.size()) {
                v.push_back(i);
            }
        }
        return v;
    }
};