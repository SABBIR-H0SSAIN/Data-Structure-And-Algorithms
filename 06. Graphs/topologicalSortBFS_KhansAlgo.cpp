// Problem Link : https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        vector<int>ans;
        vector<int>indegree(adj.size(),0);
        queue<int>q;
        
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        
        for(int i=0;i<adj.size();i++){
            if(indegree[i]==0)q.push(i);
        }
        
        while(!q.empty()){
            
            int node=q.front();
            ans.push_back(node);
            q.pop();
            
            for(int child : adj[node]){
                indegree[child]--;
                
                if(indegree[child]==0){
                    q.push(child);
                }
            }
        }
        return ans;
    }
};
