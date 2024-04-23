class Solution {
public:
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjlist;
        for (auto edge: edges)
        {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        q.push(n - 1);
        set<int> visit;
        visit.insert(n - 1);

        int far1;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            far1 = curr;
            
            for (auto neigh: adjlist[curr])
            {
                if (visit.find(neigh) == visit.end())
                {
                    q.push(neigh);
                    visit.insert(neigh);
                }
            }
        }

        visit.clear();
        q.push(far1);
        visit.insert(far1);

        vector<int> dist(n, INT_MIN);

        int far2;
        int len = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto curr = q.front();
                q.pop();

                far2 = curr;

                dist[curr] = max(dist[curr], len);

                for (auto neigh: adjlist[curr])
                {
                    if (visit.find(neigh) == visit.end())
                    {
                        q.push(neigh);
                        visit.insert(neigh);
                    }
                }
            }

            len++;
        }

        visit.clear();
        q.push(far2);
        visit.insert(far2);

        len = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto curr = q.front();
                q.pop();
                
                dist[curr] = max(dist[curr], len);

                for (auto neigh: adjlist[curr])
                {
                    if (visit.find(neigh) == visit.end())
                    {
                        q.push(neigh);
                        visit.insert(neigh);
                    }
                }
            }

            len++;
        }

        int mind = *min_element(dist.begin(), dist.end());

        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == mind)
                res.push_back(i);
        }

        return res;        
    }
};