class Solution {
public:
     string minRemoveToMakeValid(string s) {
        int open = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++open;
            } else if (s[i] == ')') {
                if (open == 0) {
                    s.erase(i, 1);
                    --i; 
                } else {
                    --open;
                }
            }
        }
        for (int i = s.size() - 1; open > 0 && i >= 0; --i) {
            if (s[i] == '(') {
                s.erase(i, 1);
                --open;
            }
        }

        return s;
    }
};