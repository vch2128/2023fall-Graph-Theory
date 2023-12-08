#include<iostream>
#include<vector>
#include<queue>
#include<array>
#include<climits>
#define ll long long
#define pii pair<int,int>
using namespace std;

void dijkstra(int n,int m){
    //insert edges
    vector<pii> edges[n];
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        u--;
        v--;
        edges[v].push_back(make_pair(u,w));
    }
    
    priority_queue <pii, vector<pii>, greater<pii> > pq;   //{distance,v}
    int cur;
    vector<ll> dist(n,-1);

    dist[0]=0;
    pq.push(make_pair(0,0));

    while(!pq.empty()){           
        cur=pq.top().second;
        pq.pop();
            
        for(size_t k=0;k<edges[cur].size();k++){
            int v=edges[cur][k].first;
            int vd=edges[cur][k].second;
            if(dist[cur]!=-1){
                if(dist[cur]+vd < dist[v] || dist[v]==-1){
                    dist[v]=dist[cur]+vd;
                    pq.push(make_pair(dist[v],v));
                }   
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
}

void dddijkstra(int n,int m){
    //insert edges
    vector<pii> edges[n];
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        u--;
        v--;
        edges[v].push_back(make_pair(u,w));
    }
    
    priority_queue <pii, vector<pii>, greater<pii> > pq;   //{distance,v}
    int cur;
    vector<ll> distz(n,-1);
    
    distz[0]=0;
    pq.push(make_pair(0,0));

    while(!pq.empty()){           
        cur=pq.top().second;
        pq.pop();
            
        for(size_t k=0;k<edges[cur].size();k++){
            int v=edges[cur][k].first;
            int vd=edges[cur][k].second;
            if(distz[cur]!=-1){
                if(distz[cur]+vd < distz[v] || distz[v]==-1){
                    distz[v]=distz[cur]+vd;
                    pq.push(make_pair(distz[v],v));
                }   
            }
        }
    }

    vector<ll> distn(n,-1);
    distn[n-1]=0;
    pq.push(make_pair(0,n-1));

    while(!pq.empty()){           
        cur=pq.top().second;
        pq.pop();
            
        for(size_t k=0;k<edges[cur].size();k++){
            int v=edges[cur][k].first;
            int vd=edges[cur][k].second;
            if(distn[cur]!=-1){
                if(distn[cur]+vd < distn[v] || distn[v]==-1){
                    distn[v]=distn[cur]+vd;
                    pq.push(make_pair(distn[v],v));
                }   
            }
        }
    }
    
    vector<ll> dist(n,-1);
    for(int i=0;i<n;i++){
        if(distz[i]!=-1 && distn[i]!=-1){
            dist[i]=distz[i]+distn[i];
            pq.push(make_pair(distz[i]+distn[i],i));
        }
    }

    while(!pq.empty()){
        int v=pq.top().second;
        pq.pop();

        for(size_t i=0;i<edges[v].size();i++){
            int ver=edges[v][i].first;
            int verd=edges[v][i].second;
            if(dist[v]!=-1){
                if(dist[v]+verd<dist[ver] || dist[ver]==-1){
                    dist[ver]=dist[v]+verd;
                    pq.push(make_pair(dist[ver],ver));
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
}


int main(){
    int test,sub;
    cin>>test>>sub;
    int n,m,k;

    for(int i=0;i<test;i++){
        cin>>n>>m>>k;
        if(k==1){
            dijkstra(n,m);
        }
        else if(k==2){
            dddijkstra(n,m);
        }
        cout<<endl;
    }
}