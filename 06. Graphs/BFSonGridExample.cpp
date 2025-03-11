// Author : Sabbir Hossain
// Problem Link : https://leetcode.com/problems/rotting-oranges/

class Solution {
public:

    int fx[4]={-1,1,0,0};
    int fy[4]={0,0,-1,1};

    int orangesRotting(vector<vector<int>>& grid) {

         queue<pair<pair<int,int>,int>>q;
         const int m=grid.size();
         const int n=grid[0].size();
         int fresh=0;
         vector<vector<int>>vis(m,vector<int>(n,0));

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
         }

         if(fresh==0) return 0;
         int rotten=0;
         int minute=0;

         while(!q.empty()){

            int r=q.front().first.first;
            int c=q.front().first.second;
            int count=q.front().second;
            minute=max(minute,count);
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+fx[i];
                int nc=c+fy[i];

                if(nr >=0 && nc>=0 && nr<m && nc <n){
                    if(vis[nr][nc] !=1 && grid[nr][nc]==1){
                        q.push({{nr,nc},count+1});
                        grid[nr][nc]=2;
                        vis[nr][nc]=1;
                        rotten++;
                    }
                }
            }
         }

        return fresh-rotten == 0 ? minute : -1;
    }
};
