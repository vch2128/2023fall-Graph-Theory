#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long,long long>
#define ll long long

vector<ll> weight;


void clear(){
    weight.clear();
}

void prims(int n,vector<pii> offer[]){
    vector<bool> visited(n,false);
    vector<int> curdis(n,0);
    ll coins=0;
    ll mindis,newv=0;
    visited[0]=true;
    
    priority_queue <pii,vector<pii>,greater<pii> > pq;
    //{distance,vertex}
    for(int i=0;i<n;i++){
        pq.push(make_pair(weight[0]+weight[i],i));
        //cout<<"a w"<<weight[0]+weight[i]<<" v"<<i<<endl;
        curdis[i]=weight[0]+weight[i];
    }
    for(size_t i=0;i<offer[0].size();i++){
        pq.push(make_pair(offer[0][i].second,offer[0][i].first));
        curdis[offer[0][i].first]=offer[0][i].second;
        //cout<<"b w"<<weight[0]+weight[i]<<" v"<<i<<endl;
    }

    while(!pq.empty()){
        newv=pq.top().second;
        mindis=pq.top().first;
        pq.pop();
        //cout<<"n "<<newv<<" d "<<mindis<<endl;

        if(visited[newv]==true){
            //cout<<"skip"<<endl;
            continue;
        }
        
        coins+=mindis;

        visited[newv]=true;
        for(int i=0;i<n;i++){
            if(curdis[i]>weight[newv]+weight[i]&& visited[i]==false){
                curdis[i]=weight[newv]+weight[i];
                pq.push(make_pair(curdis[i],i));
                //cout<<"c w"<<curdis[i]<<" v"<<i<<endl;
            }
        }
        for(size_t i=0;i<offer[newv].size();i++){
            if(visited[offer[newv][i].first]==false){
                pq.push(make_pair(offer[newv][i].second,offer[newv][i].first));
                curdis[offer[newv][i].first]=offer[newv][i].second;
                //cout<<"d w"<<curdis[offer[i][1]]<<" v"<<offer[i][1]<<endl;
            }
        }
    }

    cout<<coins<<endl;
}

void constructdis(int n,int m){
    int w;
    vector<pii> offer[n];
    for(int i=0;i<n;i++){
        cin>>w;
        weight.push_back(w);
    }
    
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        u--;
        v--;
        if(weight[u]+weight[v]>w){
            offer[u].push_back(make_pair(v,w));
            offer[v].push_back(make_pair(u,w));
        }
    }
    prims(n,offer);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q,n,m;
    cin>>q;

    for(int k=0;k<q;k++){
        cin>>n>>m;
        clear();
        constructdis(n,m);
    }
    return 0;
}