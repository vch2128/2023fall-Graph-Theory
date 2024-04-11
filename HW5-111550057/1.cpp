#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool adj[20][20];
int deg[20];
int n;

bool findk5(){
    vector<int> ep;  
    for(int i=1;i<=n;i++){
        if(deg[i]==4){
            ep.push_back(i);    //if degree is 4, then it is an endpoint
        }
    }
    if(ep.size()!=5){
        return false;
    }
    while(1){        //subdivision
        bool fl=true;
        for(int i=1;i<=n;i++){
            if(deg[i]==2){
                fl=false;
                deg[i]=0;
                int a = -1,b;
                for(int j =1;j<=n;j++){
                    if(adj[i][j]){
                        if(a==-1)a = j;
                        else b = j;
                    }
                }
                adj[i][a]=0;
                adj[a][i]=0;
                adj[i][b]=0;
                adj[b][i]=0;
                adj[a][b]=1;
                adj[b][a]=1;
            }
        }
        if(fl){
            break;   //no more deg==2
        }
    }
    int ed=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(adj[ep[i]][ep[j]]){
                ed++;
            }
        }
    }
    if(ed==20){
        return true;
    }
    return false;
}

bool findk33(){
    vector<int> ep;
    for(int i=1;i<=n;i++){
        if(deg[i]==3){
            ep.push_back(i);
        }
    }
    if(ep.size()!=6){
        return false;
    }
    // else{
    //     for(int i=0;i<6;i++){
    //         cout<<"ep "<<ep[i]<<endl;
    //     }
    // }
    while(1){        //subdivision
        bool fl=true;
        for(int i=1;i<=n;i++){
            if(deg[i]==2){
                //cout<<"d "<<i<<endl;
                fl=false;
                deg[i]=0;
                int a = -1,b;
                for(int j =1;j<=n;j++){
                    if(adj[i][j]){
                        if(a==-1)a = j;
                        else b = j;
                    }
                }
                //cout<<"a "<<a<<" b "<<b<<endl;
                adj[i][a]=0;
                adj[a][i]=0;
                adj[i][b]=0;
                adj[b][i]=0;
                adj[a][b]=1;
                adj[b][a]=1;
            }
        }
        if(fl){
            break;   //no more deg==2
        }
    }
    vector<int> u;           //bipartite
    vector<int> d;
    u.push_back(ep[0]);
    for(int i=1;i<6;i++){
        if(adj[ep[0]][ep[i]]){
            d.push_back(ep[i]);
        }
        else{
            u.push_back(ep[i]);
        }
    }
    if(u.size()!=3||d.size()!=3){
        return false;
    }
    int ed=0;
    for(int i=0;i<u.size();i++){
        for(int j=0;j<d.size();j++){
            if(adj[u[i]][d[j]]){
                ed++;
            }
        }
    }
    if(ed==9){
        return true;
    }
    return false;
}

void isplanar(){
    int m,a,b;
    cin>>n>>m;
    vector< pair<int,int> > edge(m);
    for(int i=0;i<m;i++){
        cin>>edge[i].first>>edge[i].second;
    }

    if(m>(3*n-6)){
        cout<<"No\n";
        return;
    }

    for(int i=1;i<(1<<m);i++){
        memset(adj,0,sizeof(adj));
        memset(deg,0,sizeof(deg));
        for(int j=0;j<m;j++){
            if((i>>j)&1){
                a=edge[j].first;
                b=edge[j].second;
                deg[a]++;
                deg[b]++;
                adj[a][b]=true;
                adj[b][a]=true;
            }
        }
        if(findk33()||findk5()){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        isplanar();
    }
    return 0;
}