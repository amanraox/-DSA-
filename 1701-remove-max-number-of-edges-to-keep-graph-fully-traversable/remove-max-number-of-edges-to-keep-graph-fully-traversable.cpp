class Solution {
public:
class DSU {
    public:
    vector<int>rank,parent,size;

    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int node){
        if(node==parent[node]) return node;

        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};


    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
           DSU ds1(n+1),ds2(n+1);   int ans=0;
           int a=-1,b=-1;
           for(auto edge:edges){
              int val=edge[0];
              if(val==3){
                
                   
                  if(ds2.findUPar(edge[1])!=ds2.findUPar(edge[2])&&ds1.findUPar(edge[1])!=ds1.findUPar(edge[2])){
                        ds2.unionBySize(edge[1],edge[2]);
                        ds1.unionBySize(edge[1],edge[2]);
                   }else{
                        ans++;
                   }
                   a=ds1.findUPar(edge[1]);
                   b=ds2.findUPar(edge[1]);
              }
             // cout<<a<<" "<<b<<endl;
           }
        
       
           
           for(auto edge:edges){
              int val=edge[0];
              if(val==1){
                
                   if(ds1.findUPar(edge[1])!=ds1.findUPar(edge[2])){
                        ds1.unionBySize(edge[1],edge[2]);
                   }else{
                        ans++;
                   }

                    a=ds1.findUPar(edge[1]);
              }else if(val==2){
                    if(ds2.findUPar(edge[1])!=ds2.findUPar(edge[2])){
                        ds2.unionBySize(edge[1],edge[2]);
                   }else{
                        ans++;
                   }

                    b=ds2.findUPar(edge[1]);
              }
           }
             // cout<<ds1.size[a]<<" "<<ds2.size[b]<<endl;
           if(a!=-1&&b!=-1&&ds1.size[a]==n && ds2.size[b]==n){
                     return ans;
           }else{
                     return -1;
           }        
    }
};