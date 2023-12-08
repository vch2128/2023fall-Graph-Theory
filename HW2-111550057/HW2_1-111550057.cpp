// #include<iostream>
// #include<string>
// #include<algorithm>
// #include<stack>
// #include<vector>
// #include<climits>
// using namespace std;

// vector<stack<int> > allseq;

// bool cmp(string s1,string s2){
//     return (s1.length()<s2.length());
// }
// bool cmp2(string s1,string s2){
//     return s1<s2;
// }
// bool cmp3(string s1,string s2){
//     return s1>s2;
// }

// void findpath(int vinset,int lastv,stack<int> seq,vector<vector<vector<int> > > path){
//     int prev;
//     //cout<<"findpath v"<<vinset<<" lastv"<<lastv<<endl;
//     if(vinset<=0){
//         cout<<"?"<<endl;
//     }
//     else if(vinset>0){
//         seq.push(lastv);
//         //cout<<"push "<<lastv<<endl;
//         prev=vinset;
//         vinset-=(1<<lastv);
//         //cout<<"vinset"<<vinset<<endl;
//         if(vinset==0){
//             allseq.push_back(seq);
//             // while(!seq.empty()){
//             //     cout<<seq.top()<<" ";
//             //     seq.pop();
//             // }
//             // cout<<endl;
//         }
//         else{
//             for(int i=0;i<path[prev][lastv].size();i++){
//                 findpath(vinset,path[prev][lastv][i],seq,path);
//             }
//         }
//     }
// }

// vector<string> removestr(vector<string> strs,int n){
//     vector<string> a;
//     vector<bool> exist(n,1); 
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(strs[j].find(strs[i])!=string::npos){
//                 exist[i]=0;
//                 break;
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         if(exist[i]==1){
//             a.push_back(strs[i]);
//         }
//     }
//     return a;
// }

// int overlapdis(string str1,string str2){
//     for(int i=0;i<str1.length();i++){
//         //cout<<str1.substr(i)<<endl;
//         if(str2.find(str1.substr(i))==0){    
//             return str2.length()-str1.length()+i;
//         } 
//     }
//     return str2.length();
// }

// string shortestSup(vector<string> strs,int n){
//     //sort(strs.begin(),strs.end(),cmp3);
//     vector< vector<int> > dis(n,vector<int>(n));
//     //cout<<n<<endl;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(i==j){
//                 dis[i][j]=0;
//             }
//             else{
//                 dis[i][j]=overlapdis(strs[i],strs[j]);
//                 dis[j][i]=overlapdis(strs[j],strs[i]);
//             }
//         }
//     }
    
//     // for(int i=0;i<n;i++){
//     //     for(int j=0;j<n;j++){
//     //         cout<<"dis["<<i<<"]["<<j<<"] = "<<dis[i][j]<<endl;
//     //     }
//     // }

//     vector< vector<int> > dp(1<<n,vector<int>(n));
//     vector< vector < vector<int> > > path(1<<n,vector< vector<int> >(n));
//     int mindis=INT_MAX,other;
//     vector<int> lastv;
    
//     for(int i=1;i<(1<<n);i++){
//         fill(dp[i].begin(),dp[i].end(),INT_MAX);
//         for(int j=0;j<n;j++){
//             if((i&(1<<j))>0){
//                 other=i-(1<<j);
//                 //cout<<"other"<<other<<endl;
//                 if(other==0){
//                     dp[i][j]=strs[j].length();
//                     //cout<<"aa dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
//                 }
//                 else{
//                     for(int k=0;k<n;k++){
//                             if(dp[other][k]<INT_MAX && dp[other][k]+dis[k][j]<dp[i][j]){
//                                 dp[i][j]=dp[other][k]+dis[k][j];
//                                 //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
//                                 if(!path[i][j].empty()){
//                                     path[i][j].clear();
//                                     path[i][j].resize(0);
//                                 }
//                                 path[i][j].push_back(k);
//                                 //cout<<"path"<<path[i][j]<<endl;
//                             }
//                             else if(dp[other][k]<INT_MAX && dp[other][k]+dis[k][j]==dp[i][j]){
//                                 //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
//                                 path[i][j].push_back(k);
//                                 //cout<<"path"<<path[i][j]<<endl;
//                             }
//                     }
//                 }
//             }
            
//             if(i==(1<<n)-1){
//                 if(mindis>dp[i][j]){
//                     if(!lastv.empty()){
//                         lastv.clear();
//                         lastv.resize(0);
//                     }
//                 mindis=dp[i][j];
//                 lastv.push_back(j);
//                 //cout<<"jjj"<<j<<endl;
//                 }
//                 else if(mindis==dp[i][j]){
//                     lastv.push_back(j);
//                 }
//             }
//        }
//     }

//     // for(int i=1;i<(1<<n);i++){
//     //     for(int j=0;j<dp[i].size();j++){
//     //         cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
//     //     }
//     // }

//     // for(int i=0;i<lastv.size();i++){
//     //     cout<<"lastv["<<i<<"]="<<lastv[i]<<" ";
//     // }
//     // cout<<endl;

//     // for(int i=1;i<(1<<n);i++){
//     //     for(int j=0;j<n;j++){
//     //         for(int k=0;k<path[i][j].size();k++){
//     //             cout<<"path["<<i<<"]["<<j<<"]["<<k<<"]="<<path[i][j][k]<<endl;
//     //         }
//     //     }
//     // }
//     //sort(lastv.begin(),lastv.end());
//     //cout<<"lastv "<<lastv[0]<<endl;
//     //reconstruct the seq of vertices
//     stack<int> seq;
//     int vinset=(1<<n)-1;//prev;   //all v in set
//     vector<string> supvec;
//     string sup;
    
//     int a=0,b=0;
//     for(int k=0;k<lastv.size();k++){
//         vinset=(1<<n)-1;
//         if(!allseq.empty()){
//             allseq.clear();
//             //cout<<"clear\n";
//         }
//         while(!seq.empty()){
//             seq.pop();
//         }
//         //cout<<"f v"<<vinset<<" k"<<k<<endl;
//         findpath(vinset,lastv[k],seq,path);

//         for(int i=0;i<allseq.size();i++){
//             seq=allseq[i];
//             a=seq.top();
//             seq.pop();

//             sup=strs[a];
//             while(!seq.empty()){
//                 b=seq.top();
//                 //cout<<"b"<<b<<" ";
//                 seq.pop();
//                 //cout<<"a"<<a<<"b"<<b<<" "<<strs[b].substr(strs[b].length()-dis[a][b])<<endl;
//                 sup+=strs[b].substr(strs[b].length()-dis[a][b]);
//                 //cout<<sup<<endl;
//                 a=b;
//             }
//             supvec.push_back(sup);
//         }
//     }
//     sort(supvec.begin(),supvec.end(),cmp2);
//     // for(int i=0;i<supvec.size();i++){
//     //     cout<<supvec[i]<<endl;
//     // }
    
//     return supvec[0];
// }

// int main(){
//     int n;
//     cin>>n;
//     string temp;
//     vector<string> strs;
//     for(int i=0;i<n;i++){
//         cin>>temp;
//         strs.push_back(temp);
//     }
//     sort(strs.begin(),strs.end(),cmp);

//     strs=removestr(strs,n);
//     n=strs.size();
//     // for(int i=0;i<strs.size();i++){
//     //     cout<<endl<<strs[i];
//     // }
//     //cout<<endl;

//     cout<<shortestSup(strs,n);
//     return 0;
// }

