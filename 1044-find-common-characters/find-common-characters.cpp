class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> common;

        int countCommon[26];
        for (char& ch : words[0]) {
            countCommon[ch - 'a']++;
        }

        int n = words.size();
        int freqCurr[26];

        for (int i = 1; i < n; i++) {
            
            for (char& ch : words[i]) {
                freqCurr[ch - 'a']++;
            }

            for (int j = 0; j < 26; j++) {
                countCommon[j] = min(countCommon[j], freqCurr[j]);
                freqCurr[j] = 0;
            }
        }

        for (int j = 0; j < 26; j++) {

            if (countCommon[j] != 0) {
                int k = countCommon[j];

                while (k > 0) {
                    common.push_back(string(1, (j + 'a')));
                    k--;
                }
            }
        }
        return common;
    }
};