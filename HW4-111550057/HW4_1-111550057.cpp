#include<iostream>
#include<vector>
#include<algorithm>
#define vi vector<int>
#define vb vector<bool>
using namespace std;

void findcut(vector<int> adj[],int v,vi& disc,vi& low,vb& vis,vb& iscut,int& time,int parent){
    vis[v]=true;
    int children=0;
    disc[v]=low[v]=++time;

    for(int i=0;i<adj[v].size();i++){
        if(!vis[adj[v][i]]){
            children++;
            findcut(adj,adj[v][i],disc,low,vis,iscut,time,v);

            low[v]=min(low[v],low[adj[v][i]]);

            if(parent!=-1 && low[adj[v][i]]>=disc[v]){
                iscut[v]=true;
            }
        }
        else if (adj[v][i] != parent)
            low[v] = min(low[v], disc[adj[v][i]]);
    }
    if(parent==-1 && children>1){
        iscut[v]=true;
    }
}

void cv(vector<int> adj[],int n){
    vector<int> disc(n,0);
    vector<int> low(n,0);
    vector<bool> vis(n,false);
    vector<bool> iscut(n,false);
    int time=0;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            findcut(adj,i,disc,low,vis,iscut,time,-1);
        }
    }
    vector<int> c;
    for(int i=0;i<n;i++){
        if(iscut[i]){
            c.push_back(i+1);
        }
    }
    cout<<c.size()<<endl;
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<" ";
    }
}

int main(){
    int n,m,x,y;
    cin>>n>>m;
    vector<int> adj[n];

    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cv(adj,n);
    
    return 0;
}