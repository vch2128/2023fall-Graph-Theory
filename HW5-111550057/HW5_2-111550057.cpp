#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<cstring>
using namespace std;

int total;
int work[170],dist[170];

struct edge{
    int to,rev,flow,cap;
};

inline void addedge(vector<vector<edge> >& network, int s, int t,int cap){
    edge a= {t,(int)network[t].size(),0,cap};
    edge b= {s,(int)network[s].size(),0,0};
    network[s].push_back(a);
    network[t].push_back(b);
}

bool bfs(vector<vector <edge> >& graph,int s,int t){
    memset(dist,-1,sizeof(dist));
    dist[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<(int)graph[u].size();i++){
            edge &e=graph[u][i];
            int v=e.to;
            if(dist[v]<0 && e.flow<e.cap){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist[t]>=0;
}

int dfs(vector<vector<edge> > &graph,int s,int t,int m){
   
    if (s == t){
        //base
        return m;
    }
    for (int &i = work[s]; i < (int) graph[s].size(); i++) {     //all s adjacent nodes
        edge &e = graph[s][i];
        if (e.cap <= e.flow){
            continue;
        } 
        int v = e.to;
        if (dist[v] == dist[s] + 1) {
            int df = dfs(graph,v,t,min(m, e.cap-e.flow));      //min: take possible flow
            if (df > 0) {
                e.flow += df;
                graph[v][e.rev].flow -= df;
                return df;
            }
        }
    }
    return 0;
}

int ford(vector<vector<edge> >& network,int s,int t){
    vector<vector <edge> > graph=network;
    int maxflow=0;
    while(bfs(graph,s,t)){
        memset(work,0,sizeof(work));
        while(1){
            int pathflow=dfs(graph,s,t,INT_MAX);
            if(!pathflow){
                break;
            }
            maxflow+=pathflow;
        }
    }
    return maxflow;
}

void conn(){
    int n,m;
    cin>>n>>m;
    total=2*n+1;
    vector< vector<edge> > network(total);
    for(int i=1;i<=n;i++){
        //1->2, 3->4...     //odd->original nodes, even->dual nodes
        addedge(network,2*i-1,2*i,1);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        addedge(network,2*a,2*b-1,1000);
        addedge(network,2*b,2*a-1,1000);
    }
    //complete graph
    if(m == (n*(n-1))/2){
        cout<<n-1<<endl;
        return;
    }
    int maxf=INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //cout<<"i"<<i<<" j"<<j<<endl;
            if(i!=j){
                maxf=min(maxf,ford(network,2*i,2*j-1));
            }
            if(maxf==2){
                cout<<maxf<<endl;
                return;
            }
        }
    }
    cout<<maxf<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    conn();
    return 0;
}