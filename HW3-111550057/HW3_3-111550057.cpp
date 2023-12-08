#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> parent;
vector<int> height;
vector<int> endp;

int findparent(int a,int b){
    if(parent[a]!=0){
        return a;
    }
    else if(parent[b]!=0){
        return b;
    }
    return 0;
}

void trace(int e){
    int h=0;
    int cur=e;
    while(cur!=-1){
        height[cur]=max(height[cur],h);
        cur=parent[cur];
        h++;
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        parent.push_back(0);
        endp.push_back(1);
        height.push_back(0);
    }
    parent[1]=-1;
    int a,b,p;

    for(int i=1;i<n;i++){
        cin>>a>>b;
        p=findparent(a,b);
        if(p==a){
            parent[b]=a;
            endp[a]=0;
        }
        else{
            parent[a]=b;
            endp[b]=0;
        }
    }

    for(int i=1;i<=n;i++){
        if(endp[i]==1){
            trace(i);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<height[i]<<" "<<parent[i]<<endl;
    }

    return 0;
}