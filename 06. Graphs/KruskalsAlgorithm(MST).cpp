// Problem Link : https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findParent(int child) {
        if (parent[child] == child) return child;
        return parent[child] = findParent(parent[child]);
    }

    bool isConnected(int u, int v) {
        return findParent(u) == findParent(v);
    }

    void connect(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (rank[u] > rank[v]) {
            parent[v] = u;
        } else if (rank[u] < rank[v]) {
            parent[u] = v;
        } else {
            parent[u] = v;
            rank[v]++;
        }
    }
    
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        DSU dsu(V);
        int MST=0;
        vector<vector<int>>e;
        
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                e.push_back({adj[i][j][1],i,adj[i][j][0]});
            }
        }
        sort(e.begin(),e.end());
        
        for(int i=0;i<e.size();i++){
            int u=e[i][1];
            int v=e[i][2];
            int wt=e[i][0];
            
            if(!dsu.isConnected(u,v)){
                dsu.connect(u,v);
                MST+=wt;
            }
        }
        return MST;
    }
};
