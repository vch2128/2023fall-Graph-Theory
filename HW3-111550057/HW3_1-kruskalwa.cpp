// #include<iostream>
// #include<vector>
// #include<climits>
// #include<algorithm>
// using namespace std;
// #define ll long long
// #define pii pair<int,int> 

// vector<int> weight;
// vector< vector<int> > edges;


// void clear(){
//     weight.clear();
//     edges.clear();
// }

// void constructdis(int n,int m){
//     int w;
//     for(int i=0;i<n;i++){
//         cin>>w;
//         weight.push_back(w);
//     }
//     int k=0;
//     vector<int> temp(3,0);
//     for(int i=0;i<n;i++){
//         //cout<<endl<<"i:"<<i<<endl<<"j:";
//         for(int j=n-1;j>k;j--){
//             //cout<<j<<" ";
//             temp[0]=weight[i]+weight[j];
//             temp[1]=i;
//             temp[2]=j;
//             edges.push_back(temp);
//             // for(int i=0;i<temp.size();i++){
//             //     cout<<temp[i]<<" ";
//             // }
//             // cout<<endl;
//         }
//         k++;
//     }

//     int u,v;
//     for(int i=0;i<m;i++){
//         cin>>u>>v>>w;
//         u--;
//         v--;
//         if(weight[u]+weight[v]>w){
//             temp[0]=w;
//             temp[1]=u;
//             temp[2]=v;
//             edges.push_back(temp);
//             //cout<<"u"<<u<<" v"<<v<<" w"<<w<<endl;
//         }
//     }
//     sort(edges.begin(),edges.end());
// }

// void kruskal(int n){
//     vector<bool> visited(n,0);
//     ll coins=0;
//     int mindis,v1=0,v2=0;
//     int count=0;
//     for(int k=0;k<edges.size();k++){
//         mindis=edges[k][0];
//         v1=edges[k][1];
//         v2=edges[k][2];
//         //cout<<"v1:"<<v1<<" v2:"<<v2<<" dis:"<<mindis<<endl;

//         if(visited[v1]==1&&visited[v2]==1){
//             //cout<<"no"<<endl;
//             continue;
//         }
//         else if(visited[v1]==0&&visited[v2]==0){
//             coins+=mindis;
//             visited[v1]=1;
//             visited[v2]=1;
//             count+=2;
//             //cout<<"+2"<<endl;
//         }
//         else{
//             coins+=mindis;
//             visited[v1]=1;
//             visited[v2]=1;
//             count++;
//             //cout<<"+1"<<endl;
//         }
//         if(count==n){
//             break;
//         }
//     }
//     cout<<coins<<endl;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int q,n,m;
//     cin>>q;

//     for(int k=0;k<q;k++){
//         clear();
//         cin>>n>>m;
//         constructdis(n,m);
//         kruskal(n);
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
#define pii pair<int, int>

vector<int> weight;
vector<vector<int>> edges;

void clear() {
    weight.clear();
    edges.clear();
}

void constructDis(int n, int m) {
    int w;
    for (int i = 0; i < n; i++) {
        cin >> w;
        weight.push_back(w);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({weight[i] + weight[j], i, j});
        }
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        if (weight[u] + weight[v] > w) {
            edges.push_back({w, u, v});
        }
    }

    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
}

int findParent(int vertex, vector<int>& parent) {
    if (parent[vertex] == vertex) {
        return vertex;
    }
    return parent[vertex] = findParent(parent[vertex], parent);
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else {
        parent[rootU] = rootV;
        rank[rootV]++;
    }
}

void kruskal(int n) {
    ll coins = 0;
    int count = 0;
    vector<int> parent(n);
    vector<int> rank(n, 0);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (const auto& edge : edges) {
        int w = edge[0];
        int v1 = edge[1];
        int v2 = edge[2];

        int root1 = findParent(v1, parent);
        int root2 = findParent(v2, parent);

        if (root1 != root2) {
            coins += w;
            unionSets(root1, root2, parent, rank);
            count++;
            if (count == n - 1) {
                break;
            }
        }
    }

    cout << coins << endl;
}

int main() {
    int q, n, m;
    cin >> q;

    for (int k = 0; k < q; k++) {
        clear();
        cin >> n >> m;
        constructDis(n, m);
        kruskal(n);
    }

    return 0;
}
