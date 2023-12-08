//
//  main.cpp
//  graph theory hw0
//
//  Created by 莊婷馨 on 2023/9/18.
//

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,a,maxnum=0,maxcount=0,count=0;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());
    
    maxnum=v[0];
    maxcount=1;
    count=1;
    
    for(int i=1;i<n;i++){
        if(v[i]==v[i-1]){
            count++;
        }
        else{
            if(count>=maxcount){
                maxnum=v[i-1];
                maxcount=count;
            }
            count=1;
        }
    }
    cout<<maxnum<<" "<<maxcount;
    return 0;
}
*/
