// Problem Link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class DSU {
    int n;
    vector<int>parent,rank;

    public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }
    
    void unite(int a,int b){
        int u=find(a);
        int v=find(b);
        
        if(u==v) return;
        
        if(rank[u] < rank[v]){
            parent[u]=v;
        }else if(rank[u] > rank[v]){
            parent[v]=u;
        }else{
            parent[u]=v;
            rank[v]++;
        }
    }
    
    bool isConnected(int u,int v){
        return find(u)==find(v);
    }
};

bool comp(vector<int>&a,vector<int>&b){
    return a[2] < b[2];
}

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        DSU dsu(V);
        sort(edges.begin(),edges.end(),comp);
        int cost=0;
        
        for(auto e: edges){
            int u,v,w;
            u=e[0];
            v=e[1];
            w=e[2];
            
            if(!dsu.isConnected(u,v)){
                dsu.unite(u,v);
                cost+=w;
            }
        }
        
        return cost;
    }
};
