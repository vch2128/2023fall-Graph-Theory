#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool checkSkip(vector<int> skip,vector< pair<int,int> > edges,int* color,bool fl){
    int src,to;
    vector<int> newvec;
    int detached=0;
    for(int i=0;i<skip.size();i++){
        src=edges[skip[i]].first;
        to=edges[skip[i]].second;
        
        //both no color
        if(color[src]==-1&&color[to]==-1){
            detached++;
            if(detached==skip.size()){
                color[src]=0;
                color[to]=1;
            }
            else{
                newvec.push_back(skip[i]);
            }
        }
        //only src colored
        else if(color[src]!=-1&&color[to]==-1){
            color[to]=1-color[src];
        }
        //only to colored
        else if(color[to]!=-1&&color[src]==-1){
            color[src]=1-color[to];
        }
        //both colored and same
        else if(color[to]!=-1&&color[to]==color[src]){
            fl=false;
        }
    }

    if(newvec.size()!=0&&fl==true){
        fl=checkSkip(newvec, edges, color,fl);
    }
    
    return fl;
}

int main(){
    int ver,edg;
    cin>>ver>>edg;
    
    vector< pair<int,int> > edges;
    int a,b;
    for(int i=0;i<edg;i++){
        cin>>a>>b;
        if(a>b){
            swap(a,b);
        }
        edges.push_back(make_pair(a, b));
    }
    sort(edges.begin(),edges.end());
    
    int color[ver+1];
    for(int i=1;i<=ver;i++){
        color[i]=-1;
    }
    
    int src=edges[0].first;
    color[src]=1;
    int to;
    bool f=true;
    vector<int> skip;
    
    for(int i=0;i<edg;i++){
        src=edges[i].first;
        to=edges[i].second;
        if(src==to){
            f=false;
            break;
        }
        //both no color
        if(color[src]==-1&&color[to]==-1){
            skip.push_back(i);
        }
        //only src colored
        else if(color[src]!=-1&&color[to]==-1){
            color[to]=1-color[src];
        }
        //only to colored
        else if(color[to]!=-1&&color[src]==-1){
            color[src]=1-color[to];
        }
        //both colored and same
        else if(color[to]!=-1&&color[to]==color[src]){
            f=false;
            break;
        }
    }
    
    if(skip.size()!=0&&f==true){
        f=checkSkip(skip, edges, color,f);
    }
    
    f? cout<<"Yes" : cout<<"No";
    
    return 0;
}

