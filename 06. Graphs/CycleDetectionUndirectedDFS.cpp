// Author Sabbir Hossain
// Practice: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

class Solution {
  public:
    bool dfs(vector<vector<int>>&adj,vector<bool>&vis,int node,int parent){
        vis[node]=true;
        
        for(int child : adj[node]){
            
            if(!vis[child]){
                if(dfs(adj,vis,child,node)) return true;
            }else if(child !=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {      
        vector<bool>vis(adj.size(),false);
      
        for(int i=0;i<adj.size();i++){
            if(vis[i]) continue;
            if(dfs(adj,vis,i,-1)) return true;
        }
        return false;
    }
};

