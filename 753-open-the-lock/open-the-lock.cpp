class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string , bool>visited;
        for(string it : deadends){
            visited[it] = true;
        }
        if(visited["0000"] == true)
            return -1;
        int ans = 0;
        queue<string>q;
        q.push("0000");
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i < n ; i ++){ 
                string temp = q.front();
                q.pop();
                if(temp == target) return ans;   
                
                for(int j = 0 ; j < 4 ; j ++){
                    string fwd = temp , bwd = temp;

                    fwd[j] < '9' ? fwd[j]++ : fwd[j] = '0';
                  
                    bwd[j] > '0' ? bwd[j]-- : bwd[j] = '9';

                    if(!visited[fwd]) {
                        visited[fwd] = true;
                        q.push(fwd);
                    }
                    if(!visited[bwd]) {
                        visited[bwd] = true;
                        q.push(bwd);
                    } 
                }

            }
            ans++;
        }
        return -1;
    }
};