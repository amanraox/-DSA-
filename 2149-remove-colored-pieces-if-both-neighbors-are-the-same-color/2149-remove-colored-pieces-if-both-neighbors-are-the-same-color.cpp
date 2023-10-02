class Solution {
public:
    bool winnerOfGame(string colors) {
        int bob=0;
        int ali=0;
       
        for(int i=1;i<colors.size()-1;i++){
            if(colors[i]==65){
        if(colors[i-1]==65 && colors[i+1]==65){
                ali++;

        }
    }
             if(colors[i]==66){
        if(colors[i-1]==66 && colors[i+1]==66){
                bob++;

        }
    }
        } 
      return ali>bob;
    }
};