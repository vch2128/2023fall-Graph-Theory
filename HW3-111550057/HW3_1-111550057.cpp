#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
#define pii pair<int,int>
#define ll long long



void prims(int n,int m){
    vector<int> weight;
    priority_queue <pii,vector<pii>,greater<pii> > pq;
    int w,min=INT_MAX,minv=0;
    for(int i=0;i<n;i++){
        cin>>w;
        weight.push_back(w);
        if(w<min){
            min=w;
            minv=i;
        }
    }
    vector<pii> offer[n]; //{dis,v}
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        u--;
        v--;
        if(weight[u]+weight[v]>w){
            offer[u].push_back(make_pair(w,v));
            offer[v].push_back(make_pair(w,u));
        }
    }

    vector<bool> visited(n,false);
    ll coins=0;
    int mindis,newv=0;
    visited[minv]=true;
    
    //{distance,vertex}
    for(int i=0;i<n;i++){
        if(i==minv){
            continue;
        }
        pq.push(make_pair(weight[minv]+weight[i],i));
    }
    for(size_t i=0;i<offer[minv].size();i++){
            pq.push(offer[minv][i]);
    }

    while(!pq.empty()){
        newv=pq.top().second;
        mindis=pq.top().first;
        pq.pop();

        if(visited[newv]==true){
            continue;
        }
        
        coins+=mindis;

        visited[newv]=true;
        
        for(size_t i=0;i<offer[newv].size();i++){
            if(visited[offer[newv][i].second]==false){
                pq.push(offer[newv][i]);
            }
        }
    }

    cout<<coins<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q,n,m;
    cin>>q;

    for(int k=0;k<q;k++){
        cin>>n>>m;
        prims(n,m);
    }
    return 0;
}