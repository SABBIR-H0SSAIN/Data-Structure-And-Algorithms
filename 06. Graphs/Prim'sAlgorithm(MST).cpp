//Problem Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

#define pii pair<int,int>
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pii>>g(V+1);
        for(auto it:edges){
            int u,v,w;
            u=it[0];
            v=it[1];
            w=it[2];
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<bool>vis(V+1,false);
        pq.push({0,0});
        int cost=0;
        
        while(!pq.empty()){
            int w=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(vis[node]) continue;
            cost+=w;
            vis[node]=true;
            
            for(auto it : g[node]){
                if(!vis[it.first]){
                    pq.push({it.second,it.first});
                }
            }
        }
        
        return cost;
    }
};
