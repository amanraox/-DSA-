class Solution {
public:
int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freqAv(26);
        for(auto ch : letters){
            freqAv[ch - 'a']++;
        }
        int maxScore = 0;
        vector<int> currSubNeeds(26);
        int size = words.size();
        for(int indxMask = 1; indxMask < (1 << size); indxMask++){
            currSubNeeds.assign(26, 0);
            for(int indx = 0; indx < size; indx++){
                if((indxMask & (1 << indx)) != 0){
                    string &currWrd = words[indx];
                    for(auto chr : currWrd){
                        currSubNeeds[chr - 'a']++;
                    }
                }
            }
            bool notPos = false;
            int scoreTotal = 0;
            for(int indx = 0; indx < 26; indx++){
                if(currSubNeeds[indx] > freqAv[indx]){
                    notPos = true;
                    break;
                }else{
                    scoreTotal += score[indx] * currSubNeeds[indx];
                }
            }
            if(!notPos)
                maxScore = max(maxScore, scoreTotal);
        }
        return maxScore;        
    }
};