class Solution {
public:
bool fxn(vector<int>& hand,int groupSize,int i,int n)
    {
        int count = 1;
        i++;
        int target = hand[i-1]+1;
        hand[i-1]=-1;
        while(i<n && count<groupSize)
        {
            if(hand[i]==target)
            {
                target = hand[i]+1;
                hand[i]=-1;
                count++;
            }
            i++;
        }
        return count==groupSize;

    }
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        int n = hand.size();
        if (n%groupSize != 0)
        {
            return 0;
        }
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++)
        {
            if (hand[i]>=0)
            {
                if (!fxn(hand,groupSize,i,n))
                {
                    return 0;
                }   
            }
        }
        return 1;        
    }
};