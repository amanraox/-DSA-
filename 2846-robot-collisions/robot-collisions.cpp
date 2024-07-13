class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        map<int , pair<int , char>> mp;
        for(int i=0;i<n;i++)
        {
            mp[positions[i]].first=healths[i];
            mp[positions[i]].second=directions[i];
        }
        stack<pair<int , pair<int , char>>> st;
        for(auto it:mp)
        {
            if(!st.empty() && it.second.second=='L')
            {

                if(st.top().second.second=='R')
                {
                    if(it.second.first<st.top().second.first)
                    {
                        st.top().second.first-=1;
                        continue;
                    }
                    else if(st.top().second.first<it.second.first)
                    {
                        while(!st.empty() && it.second.first>st.top().second.first &&st.top().second.second=='R' )
                        {
                            it.second.first-=1;
                            st.pop();
                        }
                        if(!st.empty() && it.second.first==st.top().second.first &&  st.top().second.second=='R')
                        {
                            st.pop();
                            continue;
                        }
                        if(!st.empty() && it.second.first<st.top().second.first &&  st.top().second.second=='R' )
                        {
                            st.top().second.first-=1;
                            continue;
                        }
   
                    }
                    else
                    {
                        st.pop();
                        continue;
                    }
                }   
            }
            st.push(it);
        }
        vector<int> res;
        unordered_map<int , int> mp1;
        while(!st.empty())
        {
           mp1[st.top().first]=st.top().second.first;
            st.pop();
        }
        for(int i=0;i<n;i++)
        {
            if(mp1.find(positions[i])!=mp1.end())
            {
                res.push_back(mp1[positions[i]]);
            }
        }

       
        return res;
    }
};