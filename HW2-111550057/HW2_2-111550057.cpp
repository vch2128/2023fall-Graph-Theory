// #include<iostream>
// #include<vector>
// using namespace std;

// int last;

// void dfs(bool* visited,vector<int>* adj,int cur,int len,int& maxlen){
//     visited[cur]=true;
//     len++;
//     int x;
//     for(int i=0;i<adj[cur].size();i++){
//         x=adj[cur][i];
//         if(!visited[x]){
//             if(len>maxlen){
//                 maxlen=len;
//                 last=x;
//             }
//             dfs(visited,adj,x,len,maxlen);
//         }
//     }    
// }

// void dfsForDiam(vector<int>* adj,int start,int n,int& maxlen){
//     bool visited[n+1];

//     for(int i=1;i<=n;i++){
//         visited[i]=false;
//     }

//     dfs(visited,adj,start,0,maxlen);
// }

// int diam(vector<int>* adj,int n){
//     int maxlen=0,x;
//     //start at random vertex
//     dfsForDiam(adj,1,n,maxlen);
//     dfsForDiam(adj,last,n,maxlen);
//     return maxlen;
// }

// int main(){
//     int n=0,x=0,y=0;
//     cin>>n;
//     //adjacency list
//     vector<int>* adj=new vector<int>[n+1];
//     for(int i=0;i<n-1;i++){
//         cin>>x>>y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
//     cout<<diam(adj,n);

//     return 0;
// }