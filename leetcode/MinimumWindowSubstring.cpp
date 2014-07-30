class Solution {
public:
    bool contains(int *target, int *src) {
        for (int i = 0; i < 256; i++) {
            if (target[i] > src[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string S, string T) {
        int start = -1, end = -1;
        int minL = numeric_limits<int>::max();
        int target[256] = {0};
        for (char c : T) {
            target[c] ++;
        }
        
        queue<int> q;
        int src[256] = {0};
        for (int i = 0; i < S.size(); i++) {
            if (target[S[i]] > 0) {
                q.push(i);
                src[S[i]] ++;
                while (q.size() >= T.size() && contains(target, src)) {
                    int s = q.front();
                    q.pop();
                    src[S[s]]--;
                    int e = i;
                    
                    if (e - s < minL) {
                        minL = e - s;
                        start = s;
                        end = i;
                    }
                }
            }
        }
        if (start == -1) return "";
        return S.substr(start, end - start + 1);
    }
};