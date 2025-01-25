// Author: Sabbir Hossain
// Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

class Solution {
  public:
    bool bfs(vector<vector<int>>&adj,vector<bool>vis,int source){

        queue<pair<int,int>>q;
        q.push({source,-1});
        vis[source]=true;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
    
            for(int child : adj[node]){
                if(vis[child] && child != parent) return true;
                
                if(!vis[child]){
                     q.push({child,node});
                     vis[child]=true;
                }
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        
        vector<bool>vis(adj.size(),false);
        for(int i=0;i<adj.size();i++){
            if(vis[i]) continue;
            if(bfs(adj,vis,i)) return true;
        }
        return false;
    }
};
