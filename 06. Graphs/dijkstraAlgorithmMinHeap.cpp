// Problem Link : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        
        vector<int>dist(adj.size(),INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        dist[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                
                int child =it.first;
                int wt =it.second;
                
                if (distance > dist[node]) continue;
                
                if(dist[node]+wt < dist[child]){
                    dist[child]=dist[node]+wt;
                    pq.push({dist[child],child});
                }
            }
        }
        return dist;
    }
};
