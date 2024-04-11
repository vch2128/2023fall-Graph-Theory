#include<iostream>
#include<vector>
#define vvi vector<vector<int> >

using namespace std;


void dfs(vector<int> adj[],vector<bool>& vis,int cut,int cur){
    vis[cur]=1;
    //cout<<"cur "<<cur<<endl;;
    for(int i=0;i<adj[cur].size();i++){
        if(adj[cur][i]!=cut && vis[adj[cur][i]]==0){
            //cout<<"dfs2 cut"<<cut<<endl;
            dfs(adj,vis,cut,adj[cur][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,x,y;
    cin>>n>>m;
    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> c;
    int cc=0;
    for(int cut=1;cut<=n;cut++){
        vector<bool> vis(n+1,0);
        int flag=0;
        for(int i=1;i<=n;i++){
            if(i!=cut && !vis[i]){
                flag++;
                //cout<<"flag "<<flag<<endl;
                //cout<<"dfs1 cut"<<cut<<" i"<<i<<endl;
                dfs(adj,vis,cut,i);
                //cout<<endl;
            }
        }
        if(flag>1){
            c.push_back(cut);
            cc++;
        }
    }
    cout<<cc<<endl;
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<" ";
    }

    return 0;
}