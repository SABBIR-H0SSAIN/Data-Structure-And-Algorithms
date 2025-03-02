// Problem Link : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    bool isCyclic(vector<vector<int>> &adj) {
        
        vector<int>indegree(adj.size(),0);
        queue<int>q;
        int topoCount=0;
        
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            topoCount++;
            
            for(int neighbour : adj[node]){
                indegree[neighbour]--;
                
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        
        return topoCount==adj.size() ? false : true;
    }
};
