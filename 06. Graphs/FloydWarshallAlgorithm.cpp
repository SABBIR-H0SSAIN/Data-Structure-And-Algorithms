//Problem Link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n=dist.size();
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k] ==1e8 || dist[k][j]==1e8) continue;
                    int d=dist[i][k]+dist[k][j];
                    dist[i][j]=min(dist[i][j],d);
                }
            }
        }
    }
};
