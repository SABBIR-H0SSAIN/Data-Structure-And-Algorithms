// Problem Link : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

typedef pair<int,int> pii;
#define inf 1e8

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        int v=edges.size();
        vector<vector<pii>>g(v+1);
        vector<int>dist(v+1,inf);
        
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,src});
        dist[src]=0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            for(auto &adj: g[node]){
                int adjnode=adj.first;
                int wt=adj.second;
                
                
                if(dist[node]+wt< dist[adjnode]){
                    dist[adjnode]=dist[node]+wt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        
        return dist;
        
    }
};
