// #include<iostream>
// #include<vector>
// #include<iterator>
// #include<algorithm>
// using namespace std;

// struct bar{
//     int leaf;
//     int adjv;
//     int joint;
//     int len=0;
// }typedef Bar;

// pair<int,int> findjlen(Bar* bars,int j,int m){
//     int a=-1;
//     for(int i=0;i<m+2;i++){
//         if(bars[i].joint==j){
//             if(a==-1){
//                 a=bars[i].len;
//             }
//             else{
//                 return make_pair(a,bars[i].len);
//             }
//         }
//     }
// }

// int findlen(Bar* bars,int j,int m){
//     for(int i=0;i<m+2;i++){
//         if(bars[i].joint==j){
//             return bars[i].len;
//         }
//     }
// }

// pair<int,int> endj(vector<int>* adj,vector<bool> joint,vector<int> leaf,int m,int n,Bar* bars){
//     int prev,cur,x,len;
//     int jcount[n],size;
//     for(int i=0;i<n;i++){
//         jcount[i]=0;
//     }
//     for(int i=0;i<m+2;i++){
//         len=0;
//         bars[i].leaf=leaf[i];
//         prev=-1;
//         cur=leaf[i];
//         while(joint[cur]!=1){
//             len++;
//             if(adj[cur][0]==prev){
//                 x=adj[cur][1];
//             }
//             else{
//                 x=adj[cur][0];
//             }
//             prev=cur;
//             cur=x;
//         }
//         bars[i].adjv=prev;
//         bars[i].joint=cur;
//         bars[i].len=len;
        
//         size=adj[cur].size();
//         vector<int>::iterator iter=remove(adj[cur].begin(),adj[cur].end(),prev);
//         adj[cur].resize(size-1);
        
//         jcount[cur]++;
//     }
//     pair<int,int> endjoints=make_pair(-1,-1);
//     for(int i=0;i<n;i++){
//         if(jcount[i]==2){
//             if(endjoints.first==-1){
//                 endjoints.first=i;
//             }
//             else{
//                 endjoints.second=i;
//             }
//         }
//     }
//     return endjoints;
// }

// bool key(vector<int> ckey,vector<int>* adj,int n,int m){
//     vector<bool> joint;
//     vector<int> leaf;
//     int js=0;
//     for(int i=0;i<n;i++){
//         if(adj[i].size()==3){
//             joint.push_back(1);
//             js++;
//         }
//         else{
//             joint.push_back(0);
//         }
//         if(adj[i].size()==1){
//             leaf.push_back(i);
//         }
//     }
   
//     //joint number=key number
//     if(js!=m||leaf.size()!=m+2){
//         return false;
//     }

//     int* dkey=new int[m];
//     Bar bars[m+2];
//     pair<int,int> a;
//     int ej1,ej2;
//     a=endj(adj,joint,leaf,m,n,bars);
//     ej1=a.first;
//     ej2=a.second;
    
//     int cur=ej1,prev=-1,temp,i=1;
//     while(cur!=ej2){
//         (adj[cur][0]==prev)? temp=adj[cur][1] : temp=adj[cur][0];
        
//         if(joint[cur]==1&&cur!=ej1){
//             dkey[i]=findlen(bars,cur,m);
            
//             i++;
//         }
//         prev=cur;
//         cur=temp;
//     }

//     bool forward=0,backward=0,fsame=0,bsame=0;
//     int ejlen11,ejlen12,ejlen21,ejlen22;
//     a=findjlen(bars,ej1,m);
//     ejlen11=a.first;
//     ejlen12=a.second;
//     a=findjlen(bars,ej2,m);
//     ejlen21=a.first;
//     ejlen22=a.second;
//     bool flag=0;

//     if(m>2){
//         if(ckey[1]==dkey[1]){
//             forward=1;
//         }
//         if(ckey[1]==dkey[m-2]){
//             backward=1;
//         }

//         if(forward==1){
//             for(int i=1;i<m-1;i++){
//                 if(ckey[i]!=dkey[i]){
//                     fsame=0;
//                     break;
//                 }
//                 else{
//                     fsame=1;
//                 }
//             }
//         }
//         if(backward==1){
//             for(int i=1;i<m-1;i++){
//                 if(ckey[i]!=dkey[m-1-i]){
//                     bsame=0;
//                     break;
//                 }
//                 else{
//                     bsame=1;
//                 }
//             }
//         }
//         if(fsame==0&&bsame==0){
//             return false;
//         }  

//         if(fsame==1){
//             if(ejlen11==ckey[0]||ejlen12==ckey[0]){
//                 if(ejlen21==ckey[m-1]||ejlen22==ckey[m-1]){
//                     flag=true;
//                 }
//             }
//         }
//         if(flag==true){
//             return true;
//         }
//         if(bsame==1){
//             if(ejlen21==ckey[0]||ejlen22==ckey[0]){
//                 if(ejlen11==ckey[m-1]||ejlen12==ckey[m-1]){
//                     flag=true;
//                 }
//             }
//         }
//         if(flag==true){
//             return true;
//         }
//     }
//     else if(m==2){
//         if(ejlen11==ckey[0]||ejlen12==ckey[0]){
//             if(ejlen21==ckey[1]||ejlen22==ckey[1]){
//                 return true;
//             }
//         }
//         else if(ejlen21==ckey[0]||ejlen22==ckey[0]){
//             if(ejlen11==ckey[1]||ejlen12==ckey[1]){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int main(){
//     int n=0,a=0,b=0,m=0;
//     cin>>n;
//     vector<int>* adj=new vector<int>[n+1];
//     for(int i=0;i<n-1;i++){
//         cin>>a>>b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }
//     vector<int> ckey;
//     cin>>m;
//     for(int i=0;i<m;i++){
//         cin>>a;
//         ckey.push_back(a);
//     }
//     bool fl=key(ckey,adj,n,m);
//     if(fl==true){
//         cout<<"Yes";
//     }
//     else{
//         cout<<"No";
//     }

//     return 0;
// }