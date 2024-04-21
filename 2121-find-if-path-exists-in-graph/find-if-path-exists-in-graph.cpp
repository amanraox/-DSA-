class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 1; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        return parent[u] == u ? u : (parent[u] = find(parent[u]));
    }

    void unionByRank(int u, int v) {
        int i = find(u);
        int j = find(v);
        if (i == j)
            return;
        if (rank[i] < rank[j]) {
            parent[i] = j;
        } else if (rank[i] > rank[j]) {
            parent[j] = i;
        } else {
            parent[i] = j;
            rank[j]++;
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            uf.unionByRank(u, v);
        }
        return uf.find(source) == uf.find(destination);
    }
};