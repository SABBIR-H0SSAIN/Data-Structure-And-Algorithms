// Problem Link: https://www.spoj.com/problems/JHNSN/

#include<bits/stdc++.h>
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define inf 1e8

using namespace std;

void solve(int n,vector<tiii>&edges,int t){
    vector<int>h(n+1,inf);
    h[n]=0;
    cout<<"graph "<<t<<" ";
    for(int i=0;i<n;i++){
        edges.push_back({n,i,0});
    }
    for(int i=0;i<n;i++){
        for(auto &e : edges){
            int u,v,w;
            tie(u,v,w)=e;
            if(h[u]!=inf && h[u]+w < h[v]){
                h[v]=h[u]+w;
            }
        }
    }
        for(auto &e : edges){
            int u,v,w;
            tie(u,v,w)=e;
            if(h[u]!=inf && h[u]+w < h[v]){
                cout<<"no"<<endl<<endl;
            return;
            }
        }

    cout<<"yes"<<endl<<endl;

    for(int i=0;i<h.size();i++) cout<<h[i]<<" ";
    cout<<endl<<endl;

    edges.resize(edges.size()-n);
    vector<vector<pii>>adj(n+1);
    for(auto &e:edges){
        int u,v,w;
        tie(u,v,w)=e;
        adj[u].push_back({v,w+h[u]-h[v]});
    }

    for(int i=0;i<n;i++){
        vector<int>dist(n+1,inf);
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,i});
        dist[i]=0;

        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();

            for(auto &x : adj[node]){
                int adjnode=x.first;
                int wt=x.second;

                if(d+wt < dist[adjnode]){
                    dist[adjnode]=d+wt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }

        for(int k=0;k<n;k++){
            if(dist[k]==inf) cout<<"# ";
            else cout<<dist[k]+h[k]-h[i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}
int main(){
    int t;
    cin>>t;
    int nt=0;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<tiii>edges;
        
        while(m--){
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back({u-1,v-1,w});
        }
        solve(n,edges,++nt);
    }
}
