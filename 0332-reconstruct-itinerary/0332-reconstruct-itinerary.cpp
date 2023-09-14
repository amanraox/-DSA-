class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> itinerary;
        int n = tickets.size()+1;
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;

        for(auto i : tickets){
            adj[i[0]].push(i[1]);
        }
        function<void(string)> dfs = [&](string airport) {
            while (!adj[airport].empty()) {
                string next = adj[airport].top();
                adj[airport].pop();
                dfs(next);
            }
            itinerary.push_back(airport);
        };
    
        dfs("JFK");
    
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};