// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

const int MOD=1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
      
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        vector<vector<pair<int,int>>>g(n);
        priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> pq;

        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];

            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;

        while(!pq.empty()){
            int node=pq.top().second;
            long long wt=pq.top().first;
            pq.pop();
            
            if(wt > dist[node]) continue;

            for(auto adj : g[node]){
                int adj_node=adj.first;
                int adj_wt=adj.second;

                if(adj_wt+wt < dist[adj_node]){
                    dist[adj_node]=adj_wt+wt;
                    ways[adj_node]=ways[node];
                    pq.push({dist[adj_node],adj_node});
                    
                }else if(adj_wt+wt == dist[adj_node]){
                    ways[adj_node]=(ways[node]+ways[adj_node])%MOD;
                }
            }
        }

        return ways[n-1];
      
    }
};
