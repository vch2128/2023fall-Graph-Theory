#include<iostream>
#include<vector>
#define vb vector<bool>
#define vi vector<int>
#define vpib vector< pair<int,bool> >
using namespace std;

vpib* mon;

bool aug(vpib mon[],vi& hero,int n,int i){
    //cout<<endl<<"aug i"<<i<<endl;
    int x;
    for(int j=1;j<mon[i].size();j++){
        x=mon[i][j].first;
        //cout<<"x "<<x<<endl;
        if(!mon[i][j].second){
            //cout<<"lookup"<<endl;
            mon[i][j].second =true;
            if(hero[x]==-1 || aug(mon,hero,n,hero[x])){
                //cout<<"hero "<<hero[x]<<endl;
                hero[x]=i;
                //cout<<"t"<<endl;
                return true;
            }
        }
    }
    //cout<<"f"<<endl;
    return false;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    mon = new vpib[n+1];
    vi hero(m+1,-1);   //which hero defeat the monster
    int x,t;
    for(int i=1;i<=n;i++){
        cin>>x;
        mon[i].push_back(make_pair(x,0));
        for(int j=0;j<x;j++){
            cin>>t;
            mon[i].push_back(make_pair(t,0));
        }
    }
    int c=0;
    for(int i=1;i<=n;i++){
        //cout<<endl<<"i "<<i<<endl;;
        if(aug(mon,hero,n,i)){
            c++;
        }
    }
    
    for(int i=1;i<=n;i++){
        //cout<<endl<<"i2 "<<i<<" k"<<k<<endl;
        if(k==0){
            break;
        }
        if(aug(mon,hero,n,i)){
            c++;
            k--;
        }
    }
    cout<<c<<endl;

    return 0;
}