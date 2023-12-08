#include<iostream>
#include<vector>
using namespace std;

int main(){
    int ver=0,edge=0;
    vector<int> indegree;
    vector<int> outdegree;
    int in=0,out=0,w=0;

    cin>>ver>>edge;
    
    int **matrix=new int*[ver];
    for(int i=0;i<ver;i++){
        matrix[i]=new int[ver];
    }
    for(int i=0;i<ver;i++){
        for(int j=0;j<ver;j++){
            matrix[i][j]=0;
        }
    }

    for(int i=0;i<ver;i++){
        indegree.push_back(0);
        outdegree.push_back(0);
    }
    

    for(int i=0;i<edge;i++){
        cin>>out>>in>>w;
        indegree[in-1]+=1;
        outdegree[out-1]+=1;
        if(out<=ver&&in<=ver){
            matrix[out-1][in-1]+=w;
        }
    }

    for(int i=0;i<ver;i++){
        for(int j=0;j<ver;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<ver;i++){
        cout<<indegree[i]<<" "<<outdegree[i]<<endl;
    }
    
    for(int i=0;i<ver;i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
