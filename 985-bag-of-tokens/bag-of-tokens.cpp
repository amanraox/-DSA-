class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0;
        int maxScore=0;
        for(int i=0,j=tokens.size()-1;i<=j;){
            if(power>=tokens[i]){
                score++;
                power=power-tokens[i];
                i++;
            }
            else{
                if(score==0){
                    break;
                }
                else{
                     score--;
                    power=power+tokens[j];
                    j--;
                }
            }
            maxScore=max(maxScore,score);
        }
        return maxScore;
    }
};