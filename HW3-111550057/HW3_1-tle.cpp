#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> weight;
vector< vector<int> > dis;

void clear(){
    weight.clear();
    dis.clear();
}

void constructdis(int n,int m){
    int w;
    for(int i=0;i<n;i++){
        cin>>w;
        weight.push_back(w);
    }
    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(weight[i]+weight[j]);
        }
        dis.push_back(temp);
        temp.clear();
    }

    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        u--;
        v--;
        if(dis[u][v]>w){
            dis[u][v]=w;
            dis[v][u]=w;
        }
    }
}

void prims(int n){
    vector<int> visited(n,0);
    int coins=0;
    int mindis=INT_MAX,newv=0;
    visited[0]=1;
    for(int j=0;j<n-1;j++){
        mindis=INT_MAX;
        for(int i=0;i<n;i++){
            if(visited[i]==1){
                for(int k=0;k<n;k++){
                    if(mindis>dis[i][k] && visited[k]==0){
                        mindis=dis[i][k];
                        newv=k;
                    }
                }
            }
        }
        visited[newv]=1;
        coins+=mindis;
    }
    cout<<coins<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q,n,m;
    cin>>q;

    for(int k=0;k<q;k++){
        clear();
        cin>>n>>m;
        constructdis(n,m);
        prims(n);
    }
    return 0;
}