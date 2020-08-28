#include <bits/stdc++.h>
using namespace std;

#define MAX 1001000
#define MOD 1000000007

int sum[MAX];
vector<int> c;

int main(){
    int n, x; cin>>n>>x;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        c.push_back(z);
    }

    for(int c : ::c){
        sum[c]=1;
    }

    for(int i=0; i<x; i++){
        if(sum[i]){
            for(int c : ::c){
                if(i+c<=x){
                    sum[i+c] += sum[i];
                    sum[i+c] %= MOD;
                }
            }
        }
    }
    cout<<sum[x]<<"\n";
}
