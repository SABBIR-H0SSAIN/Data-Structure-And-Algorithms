// Problem Link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

#define inf 1e8
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>dist(V,inf);
        dist[src]=0;
        
        for(int i=0;i<V;i++){
            for(auto &e : edges ){
                int u,v,w;
                u=e[0];
                v=e[1];
                w=e[2];
                if(dist[u]!= inf && dist[u]+w<dist[v]){
                    dist[v]= dist[u]+w;
                }
            }
        }
        
         for(auto &e : edges ){
               int u,v,w;
               u=e[0];
               v=e[1];
               w=e[2];
               if(dist[u]!= inf && dist[u]+w<dist[v]){
                  return {-1};
               }
            }  
        return dist;
        
    }
};
