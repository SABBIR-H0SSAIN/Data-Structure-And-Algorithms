// Problem Link : https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
    void dfs(vector<vector<int>>& adj,vector<bool>&vis,stack<int>&st,int node){
        vis[node]=true;
        
        for(auto child : adj[node]){
            if(!vis[child]){
                dfs(adj,vis,st,child);
            }
        }
        
        st.push(node);
    }
    
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        
        vector<int>ans;
        stack<int>st;
        vector<bool>vis(adj.size(),false);
        
        for(int i=0;i<adj.size();i++){
            if(!vis[i]) dfs(adj,vis,st,i);
        }
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            ans.push_back(node);
        }
        
        return ans;
    }
};
